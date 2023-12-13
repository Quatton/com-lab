#include <stdio.h>

int main(void) {
  int a;

  int *b;

  /* 以下の二行を修正。 */

  b = &a;

  *b = 8;

  printf("%d\n", a);

  return 0;
}