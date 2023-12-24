#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort3(int* a, int* b, int* c) {
  // grabs a out, see if b and c in the right order
  if (*b > *c) {
    // if not then swap
    swap(b, c);
  }
  if (*a < *b) {
    // do nothing
    return;
  }
  swap(a, b);
  if (*b < *c) {
    // do nothing
    return;
  }
  swap(b, c);
}

// clang-format off
int main(void){

  int x[3] = {0, 0, 0};

  int i;

  for (i = 0; i < 3; i++)
      scanf("%d", &x[i]);

  sort3(&x[0], &x[1], &x[2]);

  for (i = 0; i < 3; i++)
      printf("%d\n", x[i]);


  return 0;
}