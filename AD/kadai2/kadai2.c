#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
  int idx;
  char ltr;
  struct Tree *prev;
} Tree;

Tree *pop(Tree **head) {
  if (*head == NULL) {
    return NULL;
  }

  Tree *popped = *head;

  *head = (*head)->prev;

  return popped;
}

int main(void) {
  char c;

  Tree *head = NULL;
  int idx = 0;

  char buf[1000];

  fgets(buf, sizeof(buf), stdin);

  while ((c = buf[idx]) != '\0') {
    if (c == '(') {
      // put in the stack
      Tree *new = malloc(sizeof(Tree));
      new->idx = idx;
      new->ltr = c;
      new->prev = head;
      head = new;
    }

    if (c == ')') {
      // pop from the stack
      Tree *popped = pop(&head);
      printf("%d %d\n", popped->idx, idx);
      free(popped);
    }

    idx++;
  }

  for (Tree *p = head; p != NULL;) {
    Tree *next = p->prev;
    free(p);
    p = next;
  }
}