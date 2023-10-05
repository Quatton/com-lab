#include <stdio.h>

void adjust_point(int *n) {
  if (*n < 0) {
    *n = 0;
    return;
  }
  if (*n > 100) {
    *n = 100;
    return;
  }
}

// clang-format off
int main(void){

  int x = 0;
  scanf("%d", &x);

  adjust_point(&x);

  printf("%d\n", x);

  return 0;
}