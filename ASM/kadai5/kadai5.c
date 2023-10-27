#include <stdio.h>

void swap_gt(int*, int*);

int main() {
  int x = 2;
  int y = -1;

  swap_gt(&x, &y);

  printf("x: %d, y: %d\n", x, y);
}