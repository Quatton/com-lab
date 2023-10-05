#include <stdio.h>

int main(void) {
  union {
    float f;
    int i;
  } x;

  x.i = 10;

  printf("%d\n", x.i);

  x.f = 0.01;

  printf("%d\n", x.i);

  return 0;
}