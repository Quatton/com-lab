#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

// https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
// just in case the bucket runs into a collision we will use a linked list
typedef struct hash_node {
  char* key;
  char* value;
  struct hash_node* next;
} Node;

Node* NewNode(char* key, char* value) {
  Node* head = (Node*)malloc(sizeof(Node));
  head->key = (char*)malloc(strlen(key) + 1);
  head->value = (char*)malloc(strlen(value) + 1);
  strcpy(head->key, key);
  strcpy(head->value, value);
  head->next = NULL;

  return head;
}

void Prepend(Node** list, char* key, char* value) {
  Node* new = NewNode(key, value);
  new->next = *list;
  *list = new;
}

void Print(Node** list) {
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

void Delete(Node** list, int i) {
  Node** cur = list;
  int idx = 0;
  while (*cur != NULL) {
    if (idx == i) {
      Node** temp = cur;
      *cur = (*cur)->next;
      free(temp);
      return;
    }
    cur = &((*cur)->next);
    idx++;
  }
}

int Count(Node* list) {
  if (list == NULL) return 0;
  return 1 + Count(list->next);
}

void Insert(Node** list, int i, char* key, char* value) {
  Node** cur = list;

  if (i == 0) {
    Prepend(cur, key, value);
    return;
  }

  // prev     curr
  // 3        2         1
  //         idx=1
  Node** prev = cur;
  cur = &((*cur)->next);
  int idx = 1;
  while (*prev != NULL) {
    if (idx == i) {
      Node** temp = cur;
      Prepend(temp, key, value);
      (*prev)->next = *temp;
      return;
    }
    prev = cur;
    cur = &((*cur)->next);
    idx++;
  }
}

Node** Search(Node** list, char* key) {
  Node** cur = list;
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

Node** CreateTable(void) {
  // array of pointers to nodes
  Node** hash_table = calloc(SIZE, sizeof(Node*));

  for (int i = 0; i < SIZE; i++) hash_table[i] = NULL;

  return hash_table;
}

void Set(Node** hash_table, char* key, char* value) {
  // get the hashed key
  unsigned int hashed_key = hash(key);

  // check if the key exists
  Node* cur = hash_table[hashed_key];

  if (cur == NULL) {
    Node* new = NewNode(key, value);
    hash_table[hashed_key] = new;
    return;
  }

  // if it does, find if the key inside the linked list exists
  Node** res = Search(&cur, key);

  if (res == NULL) {
    Prepend(&cur, key, value);
    return;
  }

  // else update
  strcpy(cur->value, value);
}

char* Get(Node** hash_table, char* key) {
  // get the hashed key
  unsigned int hashed_key = hash(key);

  // check if the key exists
  Node* cur = hash_table[hashed_key];

  if (cur == NULL) {
    return NULL;
  }

  // if it does, find if the key inside the linked list exists
  Node** res = Search(&cur, key);

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

void DeleteItem(Node** hash_table, char* key) {
  // get the hashed key
  unsigned int hashed_key = hash(key);

  // check if the key exists
  Node* cur = hash_table[hashed_key];

  if (cur == NULL) {
    return;
  }

  // if it does, find if the key inside the linked list exists
  Node** res = Search(&cur, key);

  if (res == NULL) {
    return;
  }

  // else remove it

  Delete(res, 0);
}

int main(void) {
  Node** fruits = CreateTable();

  while (1) {
    char* buf = malloc(256);
    // get from stdin with fgets
    if (!fgets(buf, 256, stdin)) {
      return 1;
    }

    char cmd[256];
    sscanf(buf, "%[^\n]s", cmd);

    char* cmds[3] = {NULL, NULL, NULL};

    // load into cmds
    load_cmd(cmds, cmd);

    if (strcmp(cmds[0], "quit") == 0) {
      return 0;
    }

    if (strcmp(cmds[0], "insert") == 0) {
      Set(fruits, cmds[1], cmds[2]);
    }

    if (strcmp(cmds[0], "delete") == 0) {
      DeleteItem(fruits, cmds[1]);
    }

    if (strcmp(cmds[0], "search") == 0) {
      char* res = Get(fruits, cmds[1]);
      if (res != NULL) {
        printf("%s\n", res);

      } else {
        printf("(not found)\n");
      }
    }
  }
}