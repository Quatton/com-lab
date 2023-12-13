#include <stdio.h>

int fact(int);

int main() {
  int x = 6;
  int y = fact(x);

  printf("x: %d, y: %d\n", x, y);
}