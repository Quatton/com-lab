#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int *x;

  x = calloc(1, sizeof(int));

  if (x == NULL) {
    exit(1);
  } else {
    scanf("%d", x);
    printf("%d\n", *x);
    free(x);
  }

  return 0;
}