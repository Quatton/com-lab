#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

// https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
// just in case the bucket runs into a collision we will use a linked list
typedef struct tree_node {
  char* key;
  char* value;
  struct tree_node* next;
} Tree;

Tree* NewNode(char* key, char* value) {
  Tree* head = (Tree*)malloc(sizeof(Tree));
  head->key = (char*)malloc(strlen(key) + 1);
  head->value = (char*)malloc(strlen(value) + 1);
  strcpy(head->key, key);
  strcpy(head->value, value);
  head->next = NULL;

  return head;
}

void Prepend(Tree** list, char* key, char* value) {
  Tree* new = NewNode(key, value);
  new->next = *list;
  *list = new;
}

void Print(Tree** list) {
  if (*list == NULL) {
    printf("\n");
    return;
  }
  printf("%s: %s", (*list)->key, (*list)->value);
  if ((*list)->next != NULL) {
    printf(" ");
    Print(&((*list)->next));
  } else {
    printf("\n");
  }
}

void Delete(Tree** list, int i) {
  Tree** cur = list;
  Tree* temp;
  int idx = 0;
  while (*cur != NULL) {
    if (idx == i) {
      temp = *cur;
      *cur = (*cur)->next;
      free(temp->key);
      free(temp->value);
      free(temp);
      return;
    }
    cur = &((*cur)->next);
    idx++;
  }
}

int Count(Tree* list) {
  if (list == NULL) return 0;
  return 1 + Count(list->next);
}

void Insert(Tree** list, int i, char* key, char* value) {
  Tree** cur = list;

  if (i == 0) {
    Prepend(cur, key, value);
    return;
  }

  // prev     curr
  // 3        2         1
  //         idx=1
  Tree** prev = cur;
  cur = &((*cur)->next);
  int idx = 1;
  while (*prev != NULL) {
    if (idx == i) {
      Tree** temp = cur;
      Prepend(temp, key, value);
      (*prev)->next = *temp;
      return;
    }
    prev = cur;
    cur = &((*cur)->next);
    idx++;
  }
}

Tree** Search(Tree** list, char* key) {
  Tree** cur = list;
  while (*cur != NULL) {
    if (strcmp((*cur)->key, key) == 0) {
      return cur;
    }
    cur = &((*cur)->next);
  }
  return NULL;
}

unsigned int hash(char* key) {
  unsigned int hash_value = 0;
  int key_length = strlen(key);

  for (int i = 0; i < key_length; i++) {
    hash_value = hash_value * 37 + key[i];
  }  // basically a base 37 number

  hash_value = hash_value % SIZE;

  return hash_value;
}

Tree** CreateTable(void) {
  // array of pointers to nodes
  Tree** hash_table = calloc(SIZE, sizeof(Tree*));

  for (int i = 0; i < SIZE; i++) hash_table[i] = NULL;

  return hash_table;
}

void CleanUp(Tree** table) {
  for (int i = 0; i < SIZE; i++) {
    Tree* cur = table[i];
    while (cur != NULL) {
      Tree* next = cur->next;
      free(cur->key);
      free(cur->value);
      free(cur);
      cur = next;
    }
  }
  free(table);
}

void Set(Tree** hash_table, char* key, char* value) {
  // get the hashed key
  unsigned int hashed_key = hash(key);

  // check if the key exists
  Tree* cur = hash_table[hashed_key];

  if (cur == NULL) {
    Tree* new = NewNode(key, value);
    hash_table[hashed_key] = new;
    return;
  }

  // if it does, find if the key inside the linked list exists
  Tree** res = Search(&cur, key);

  if (res == NULL) {
    Prepend(&cur, key, value);
    hash_table[hashed_key] = cur;
    return;
  }

  // else update
  char* new_value = (char*)malloc(strlen(value) + 1);
  strcpy(new_value, value);
  free((*res)->value);
  (*res)->value = new_value;
}

char* Get(Tree** hash_table, char* key) {
  // get the hashed key
  unsigned int hashed_key = hash(key);

  // check if the key exists
  Tree* cur = hash_table[hashed_key];

  if (cur == NULL) {
    return NULL;
  }

  // if it does, find if the key inside the linked list exists
  Tree** res = Search(&cur, key);

  if (res == NULL) {
    return NULL;
  }

  // else return the value
  return (*res)->value;
}

void load_cmd(char** cmd, char* buf) {
  // basically split
  char* token = strtok(buf, " ");
  int i = 0;

  // https://www.educative.io/answers/splitting-a-string-using-strtok-in-c
  // 2. Extracting all possible tokens
  while (token != NULL) {
    cmd[i] = token;
    token = strtok(NULL, " ");
    i++;
  }
}

void DeleteItem(Tree** hash_table, char* key) {
  // get the hashed key
  unsigned int hashed_key = hash(key);

  // check if the key exists
  Tree* cur = hash_table[hashed_key];

  if (cur == NULL) {
    return;
  }

  // if it does, find if the key inside the linked list exists
  Tree** res = Search(&cur, key);

  if (res == NULL) {
    return;
  }

  // else remove it
  Delete(res, 0);

  // update the hash table
  hash_table[hashed_key] = cur;
}

int main(void) {
  Tree** fruits = CreateTable();

  while (1) {
    char buf[256];
    // get from stdin with fgets
    if (!fgets(buf, sizeof(buf), stdin)) {
      return 1;
    }

    char cmd[256];
    sscanf(buf, "%[^\n]", cmd);

    char* cmds[3] = {NULL, NULL, NULL};

    // load into cmds
    load_cmd(cmds, cmd);

    if (strcmp(cmds[0], "quit") == 0) {
      break;
    }

    if (strcmp(cmds[0], "insert") == 0 && cmds[1] != NULL && cmds[2] != NULL) {
      Set(fruits, cmds[1], cmds[2]);
    }

    if (strcmp(cmds[0], "delete") == 0 && cmds[1] != NULL) {
      DeleteItem(fruits, cmds[1]);
    }

    if (strcmp(cmds[0], "search") == 0 && cmds[1] != NULL) {
      char* res = Get(fruits, cmds[1]);
      if (res != NULL) {
        printf("%s\n", res);

      } else {
        printf("(not found)\n");
      }
    }
  }

  CleanUp(fruits);
}