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
  while ((*cur)->next != NULL) {
    if (i == idx) {
      // *list =
    }
  }
}

int main() {
  Node *head = NewNode(1);
  Prepend(&head, 2);
  Prepend(&head, 3);

  Print(&head);
}