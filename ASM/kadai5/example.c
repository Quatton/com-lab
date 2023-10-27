#include <stdio.h>

void swap_gt(int* x, int* y) {
  if (*x > *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
}