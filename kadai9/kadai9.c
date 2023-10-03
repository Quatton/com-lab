#include <stdio.h>

int main(void) {
  int a[5] = {0, 0, 0, 0, 0};

  int b[5] = {0, 0, 0, 0, 0};

  int i;

  for (i = 0; i < 5; i++) scanf("%d", &a[i]);

  for (i = 0; i < 5; i++) b[4 - i] = a[i];

  for (i = 0; i < 5; i++) printf("%d\n", b[i]);

  return 0;
}