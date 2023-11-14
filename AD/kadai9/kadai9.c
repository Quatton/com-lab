#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32767

// copied from kadai1
typedef struct node {
  char* value;
  struct node* next;
} Node;

Node* NewNode(char* value) {
  Node* head = (Node*)malloc(sizeof(Node));
  head->value = malloc(strlen(value) + 1);
  strcpy(head->value, value);
  head->next = NULL;

  return head;
}

void Prepend(Node** list, char* value) {
  Node* new = (Node*)malloc(sizeof(Node));
  new->value = malloc(strlen(value) + 1);
  strcpy(new->value, value);
  new->next = *list;
  *list = new;
  // printf("%s\n", new->value);
}

void Print(Node** list) {
  if (*list == NULL) {
    printf("\n");
    return;
  }
  printf("%s\n", (*list)->value);
  if ((*list)->next != NULL) {
    Print(&((*list)->next));
  }
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

void alloc_and_setup(char** lookup, int idx, char* value) {
  if (lookup[idx] == NULL) {
    // printf("setting up %d: %s\n", idx, value);
    lookup[idx] = malloc(strlen(value) + 1);
    strcpy(lookup[idx], value);
    return;
  }
}

void load_cmd(char** lookup, int** table, char* buf) {
  // basically split
  char* token = strtok(buf, " ");
  int i = 0;
  unsigned int node1 = 0;
  unsigned int node2 = 0;

  // https://www.educative.io/answers/splitting-a-string-using-strtok-in-c
  // 2. Extracting all possible tokens
  while (token != NULL) {
    if (i == 0) {
      node1 = hash(token);
      if (table[node1] == NULL) table[node1] = calloc(SIZE, sizeof(int));
      alloc_and_setup(lookup, node1, token);
    } else if (i == 1) {
      node2 = hash(token);
      if (table[node2] == NULL) table[node2] = calloc(SIZE, sizeof(int));
      alloc_and_setup(lookup, node2, token);
    } else if (i == 2) {
      table[node1][node2] = atoi(token);
    }
    token = strtok(NULL, " ");
    i++;
  }

  // printf("loaded %d: %s, %d: %s, %d\n", node1, lookup[node1], node2,
  //        lookup[node2], table[node1][node2]);
}

void free_table(char** lookup, int** graph) {
  for (int i = 0; i < SIZE; i++) {
    free(lookup[i]);
  }
  free(lookup);

  for (int i = 0; i < SIZE; i++) {
    free(graph[i]);
  }
  free(graph);
}

int pick_min_index(int* dist, int* spt) {
  int min = INT_MAX;
  int min_index = -1;

  for (int i = 0; i < SIZE; i++) {
    if (spt[i] != 0) continue;
    if (spt[i] < min) {
      min_index = i;
      min = spt[i];
    }
  }

  return min_index;
}

void dijk(int** graph, int start, int end, Node** node, char** name_lookup) {
  // setup

  int COUNT = 0;
  int dist[SIZE];
  int spt[SIZE];     // 1 = included, 0 = not included, -1 = not in graph
  int parent[SIZE];  // we will traverse this to find the path;
  int* lookup = calloc(SIZE, sizeof(int));

  // debug
  // for (int i = 0; i < SIZE; i++) {
  //   if (graph[i] != NULL) {
  //     for (int j = 0; j < SIZE; j++) {
  //       if (graph[i][j] != 0) printf("%d ", graph[i][j]);
  //     }
  //     printf("\n");
  //   }
  // }

  for (int i = 0; i < SIZE; i++) {
    parent[i] = -1;
    if (graph[i] == NULL) {
      spt[i] = -1;
      dist[i] = INT_MAX;
      continue;
    }
    spt[i] = 0;
    dist[i] = INT_MAX;
    lookup[COUNT] = i;
    COUNT++;  // it will be constant from now. allow me.
  }

  // printf("%d\n", COUNT);

  lookup = realloc(lookup, sizeof(int) * COUNT);

  // for (int i = 0; i < COUNT; i++) {
  //   printf("%s ", name_lookup[lookup[i]]);
  // }
  // printf("\n");

  dist[start] = 0;  // so it will be picked first

  // loop through the count
  for (int count = 0; count < COUNT - 1; count++) {
    int idx = pick_min_index(dist, spt);  // will be start first;

    if (idx == end) {
      break;  // yay
    }

    spt[idx] = 1;  // marked as picked

    for (int v = 0; v < COUNT; v++) {
      int vtx = lookup[v];

      if (!spt[vtx]                // not visited
          && graph[idx][vtx]       // exists in the graph (non-zero)
          && dist[idx] != INT_MAX  // overflow prevention
          && dist[idx] + graph[idx][vtx] < dist[vtx]  // dist[vtx] should be min
      ) {  // this means that we found a new path shorter

        dist[vtx] = dist[idx] + graph[idx][vtx];
        // records who got them to the destination
        parent[vtx] = idx;
      }
    }
  }

  if (parent[end] == -1) return;

  // let's traverse the parent
  int curr_idx = end;
  while (curr_idx != start) {
    Prepend(node, name_lookup[parent[curr_idx]]);
    // printf("curr_idx: %d", curr_idx);
    curr_idx = parent[curr_idx];
  }

  free(lookup);
}

void FreeNode(Node** node) {
  if (*node == NULL) {
    return;
  }

  if ((*node)->next != NULL) {
    FreeNode(&((*node)->next));
  }

  free((*node)->value);
  free(*node);
  *node = NULL;
}

int main(void) {
  char filename[50];

  scanf("%s", filename);

  FILE* fptr;

  char buffer[250];

  fptr = fopen(filename, "r");

  // Adjacency Matrix
  int** graph = malloc(sizeof(int*) * SIZE);
  char** name_look_up = malloc(sizeof(char*) * SIZE);

  for (int i = 0; i < SIZE; i++) {
    name_look_up[i] = NULL;
  }

  for (int i = 0; i < SIZE; i++) {
    graph[i] = NULL;
  }

  int start = -1;
  int end = -1;

  while (fgets(buffer, sizeof(buffer), fptr)) {
    char readed[250];

    sscanf(buffer, "%[^\n]s", readed);

    if (start == -1) {
      start = hash(readed);
      name_look_up[start] = malloc(strlen(readed) + 1);
      strcpy(name_look_up[start], readed);
      continue;
    }
    if (end == -1) {
      end = hash(readed);
      name_look_up[end] = malloc(strlen(readed) + 1);
      strcpy(name_look_up[end], readed);
      continue;
    }

    load_cmd(name_look_up, graph, readed);
  }

  // for (int p = 0; p < 80; p++) {
  //   if (name_look_up[p]) {
  //     printf("%d: %s; ", p, name_look_up[p]);
  //   }
  // }
  // printf("\n");

  Node* path = NewNode(name_look_up[end]);

  dijk(graph, start, end, &path, name_look_up);

  Print(&path);

  FreeNode(&path);

  free_table(name_look_up, graph);
}