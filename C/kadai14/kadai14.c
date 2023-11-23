#include <stdio.h>

// euclidean?
int gcd(int x, int y) {
  if (x < y) return gcd(y, x);
  if (x % y == 0) return y;
  return gcd(y, x % y);
}

// clang-format off
int main(void){

  int x = 1, y = 1;

  scanf("%d %d", &x, &y);

  printf("%d\n", gcd(x, y));

  return 0;
}