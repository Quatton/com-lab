#include <stdio.h>

int sumup(int x) { return x * (x + 1) / 2; }

int main(void) {
  int x = 0;
  scanf("%d", &x);

  printf("%d\n", sumup(x));

  return 0;
}
