#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

int main(void) {
  unsigned int X = 0;

  int fives = 5;
  int count = 0;

  scanf("%d", &X);

  // X / 5 + X / 25 + X / 125 + ...
  while (X >= fives) {
    count += X / fives;
    fives *= 5;
  }

  printf("%d\n", count);
}