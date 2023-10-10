#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} Node;

Node *NewNode(int i) {
  Node *head = (Node *)malloc(sizeof(Node));
  head->number = i;
  head->next = NULL;

  return head;
}

void Prepend(Node **list, int i) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->number = i;
  new->next = *list;
  *list = new;
}

void Print(Node **list) {
  if (*list == NULL) {
    printf("\n");
    return;
  }
  printf("%d", (*list)->number);
  if ((*list)->next != NULL) {
    printf(" ");
    Print(&((*list)->next));
  } else {
    printf("\n");
  }
}

void Delete(Node **list, int i) {
  Node **cur = list;
  int idx = 0;
  while (*cur != NULL) {
    if (idx == i) {
      Node **temp = cur;
      *cur = (*temp)->next;
      free(*temp);
      return;
    }
    cur = &((*cur)->next);
    idx++;
  }
}

int Count(Node *list) {
  if (list == NULL) return 0;
  return 1 + Count(list->next);
}

void Insert(Node **list, int i, int j) {
  Node **cur = list;

  if (i == 0) {
    Prepend(cur, j);
    return;
  }

  // prev     curr
  // 3        2         1
  //         idx=1
  Node **prev = cur;
  cur = &((*cur)->next);
  int idx = 1;
  while (*prev != NULL) {
    if (idx == i) {
      Node **temp = cur;
      Prepend(temp, j);
      (*prev)->next = *temp;
      return;
    }
    prev = cur;
    cur = &((*cur)->next);
    idx++;
  }
}

// clang-format off
int main(void){
  int Q;
  scanf("%d", &Q);
  Node* list = NULL;

  for (int i = 0; i < Q; i++){
    int T;
    scanf("%d", &T);
    if (T == 0) {
      int N;
      scanf("%d", &N);
      Prepend(&list, N);
    } else if (T == 1) {
      printf("%d\n", Count(list));
    } else if (T == 2) {
      int N;
      scanf("%d", &N);
      Delete(&list, N);
    } else if (T == 3) {
      int N, M;
      scanf("%d %d", &N, &M);
      Insert(&list, N, M);
    } else {
      Print(&list);
    }
  }
  return 0;
}