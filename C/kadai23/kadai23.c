#include <stdio.h>

int main(void) {
  char name[100];
  char* p;

  scanf("%s", name);

  p = name;
  while (*p != '\0') {
    printf("%s\n", p);
    p++;
  }

  return 0;
}