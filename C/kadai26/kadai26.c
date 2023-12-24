#include <stdio.h>

int main(void) {
  char a[100], b[100];

  scanf("%99s", a);
  scanf("%99s", b);

  char *pa = a, *pb = b;

  while (*pa != '\0' || *pb != '\0') {
    if (*pa == '\0' || *pb == '\0' || *pa != *pb) {
      printf("NG");
      return 0;
    }

    pa++;
    pb++;
  }

  printf("OK");

  return 0;
}