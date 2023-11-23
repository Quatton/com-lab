#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node {
  char* key;
  char* value;
  struct tree_node* left;
  struct tree_node* right;
} Tree;

void setstr(char** dest, char* src) {
  *dest = (char*)malloc(strlen(src) + 1);
  strcpy(*dest, src);
}

Tree* NewNode(char* key, char* value) {
  Tree* head = (Tree*)malloc(sizeof(Tree));
  setstr(&(head->key), key);
  setstr(&(head->value), value);
  head->left = NULL;
  head->right = NULL;

  return head;
}

void Set(Tree** root, char* key, char* value) {
  // if the root is null, create a new node
  if (*root == NULL) {
    *root = NewNode(key, value);
  }

  // now let the fun begin
  // first compare the key with the root
  int cmp = strcmp(key, (*root)->key);

  if (cmp == 0) {
    // we will update the value

    free((*root)->value);  // this is the lesson i learned last time. i didn't
                           // free the old value when i updated the value

    setstr(&((*root)->value), value);
    return;
  }

  if (cmp < 0) {
    // we will set the left tree
    Set(&((*root)->left), key, value);
    return;
  }

  if (cmp > 0) {
    // we will set the right tree
    Set(&((*root)->right), key, value);
    return;
  }
}

Tree* DeleteMin(Tree** root) {
  if (*root == NULL) {
    return NULL;
  }

  if ((*root)->left == NULL) {
    // this is the min
    Tree* temp = *root;
    *root = (*root)->right;
    return temp;
  }

  return DeleteMin(&((*root)->left));
}

void DeleteItem(Tree** root, char* key) {
  int cmp = strcmp(key, (*root)->key);

  if (cmp == 0) {
    // this is kinda tricky i don't like it

    if ((*root)->right) {
      // if the right tree exists, we will delete the min of the right tree
      Tree* rmin = DeleteMin(&((*root)->right));

      // then we reset the whole tree
      rmin->left = (*root)->left;
      rmin->right = (*root)->right;

      // then we free the root value
      free((*root)->key);
      free((*root)->value);

      Tree* temp = *root;

      // now this is the new root
      *root = rmin;

      free(temp);

      return;
    }

    // if not, we will just delete the root
    Tree* temp = *root;
    *root = (*root)->left;
    free(temp->key);
    free(temp->value);
    free(temp);

    return;
  }

  if (cmp < 0) {
    // we will set the left tree
    DeleteItem(&((*root)->left), key);
    return;
  } else {
    // we will set the right tree
    DeleteItem(&((*root)->right), key);
    return;
  }
}

void CleanUp(Tree** tree) {
  if (*tree == NULL) {
    return;
  }

  CleanUp(&((*tree)->left));
  CleanUp(&((*tree)->right));

  free((*tree)->key);
  free((*tree)->value);
  free(*tree);
}

char* Get(Tree** root, char* key) {
  if (*root == NULL) {
    return NULL;
  }

  int cmp = strcmp(key, (*root)->key);

  if (cmp == 0) {
    return (*root)->value;
  }

  if (cmp < 0) {
    return Get(&((*root)->left), key);
  } else {
    return Get(&((*root)->right), key);
  }
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

int main(void) {
  Tree* fruits = NULL;

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
      Set(&fruits, cmds[1], cmds[2]);
    }

    if (strcmp(cmds[0], "delete") == 0 && cmds[1] != NULL) {
      DeleteItem(&fruits, cmds[1]);
    }

    if (strcmp(cmds[0], "search") == 0 && cmds[1] != NULL) {
      char* res = Get(&fruits, cmds[1]);
      if (res != NULL) {
        printf("%s\n", res);

      } else {
        printf("(not found)\n");
      }
    }
  }

  CleanUp(&fruits);
}