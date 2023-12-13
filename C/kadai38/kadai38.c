#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

int main(void) {
  int X = 0;

  // int fives = 5;
  int count = 0;

  scanf("%d", &X);

  if (X < 0) {
    return 0;
  }

  // X / 5 + X / 25 + X / 125 + ...
  while (X >= 5) {
    X /= 5;
    count += X;
  }

  printf("%d\n", count);
}