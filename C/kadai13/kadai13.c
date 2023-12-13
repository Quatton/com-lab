#include <stdio.h>

int fib(int n) {
  if (n == 1) return 1;
  if (n == 2) return 1;
  return fib(n - 2) + fib(n - 1);
}

int main(void) {
  int red;
  scanf("%d", &red);

  int egg = fib(red);

  printf("%d\n", egg);

  return 0;
}