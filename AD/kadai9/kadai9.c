#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define INF INT_MAX

int reverse_lookup(char lookup[][100], char *name) {
  // this looks so suboptimal lmao but let's accept it

  for (int i = 0; i < SIZE; i++) {
    if (strcmp(lookup[i], name) == 0) {
      return i;
    }
    // if not found, insert it at the first empty spot
    // in other words, if found empty spot before found the name
    if (lookup[i][0] == '\0') {
      strcpy(lookup[i], name);
      return i;
    }
  }

  return -1;  // but shouldn't reach here anyway
}

void load_graph(FILE *ptr, int graph[][SIZE], char lookup[][100]) {
  char line[100];

  // get each buffer of size 100 into line
  while (fgets(line, 100, ptr) != NULL) {
    // A B 3
    // read the first token

    char *token = strtok(line, " ");

    // get the index of the token
    int index = reverse_lookup(lookup, token);

    token = strtok(NULL, " ");
    int index2 = reverse_lookup(lookup, token);

    token = strtok(NULL, " ");
    int weight = atoi(token);

    // insert the weight into the graph
    graph[index][index2] = weight;
  }
}

int min_dist(int dist[], int sptSet[], int size) {
  int min = INF;
  int min_index;

  for (int i = 0; i < size; i++) {
    if (sptSet[i] == 0 && dist[i] <= min) {
      min = dist[i];
      min_index = i;
    }
  }

  return min_index;
}

void dijk(int graph[][SIZE], int src, int dest, int size, char lookup[][100]) {
  int sptSet[SIZE];
  int dist[SIZE];
  int parents[SIZE];
  int res[SIZE];

  // initialize
  for (int i = 0; i < size; i++) {
    sptSet[i] = 0;
    dist[i] = INF;
    parents[i] = -1;
    res[i] = -1;
  }

  dist[src] = 0;
  res[0] = dest;
  int res_size = 1;

  for (int _ = 0; _ < size; _++) {
    int u = min_dist(dist, sptSet, size);

    sptSet[u] = 1;

    for (int j = 0; j < size; j++) {
      if (sptSet[j] == 0 &&                 // unvisited
          graph[u][j] != INF &&             // edge exists
          dist[u] + graph[u][j] < dist[j])  // this shortcuts the original path
      {
        dist[j] = dist[u] + graph[u][j];

        parents[j] = u;
      }
    }
  }

  while (res[res_size - 1] != src && res[res_size - 1] != -1) {
    res[res_size] = parents[res[res_size - 1]];
    res_size++;
  }

  if (res[res_size - 1] == -1) {
    printf("(no route)\n");
    return;
  }

  for (int i = res_size - 1; i >= 0; i--) {
    printf("%s\n", lookup[res[i]]);
  }
}

int main() {
  FILE *ptr;

  char filename[100];

  scanf("%s", filename);

  ptr = fopen(filename, "r");

  if (ptr == NULL) {
    return 1;
  }

  char lookup[SIZE][100];

  for (int i = 0; i < SIZE; i++) {
    lookup[i][0] = '\0';
  }

  int graph[SIZE][SIZE];

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      graph[i][j] = (i == j) ? 0 : INF;
    }
  }

  char src[100];
  char dest[100];
  char temp[100];

  // there must be a better way lmao
  fgets(temp, 100, ptr);
  sscanf(temp, "%[^\n]", src);

  fgets(temp, 100, ptr);
  sscanf(temp, "%[^\n]", dest);

  load_graph(ptr, graph, lookup);

  int s = reverse_lookup(lookup, src);
  int d = reverse_lookup(lookup, dest);

  int GRAPH_SIZE = 0;

  for (int i = 0; i < SIZE; i++) {
    if (lookup[i][0] != '\0') {
      GRAPH_SIZE++;
    }
  }

  dijk(graph, s, d, GRAPH_SIZE, lookup);
}