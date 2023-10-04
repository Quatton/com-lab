#include <stdio.h>
int main() {
  int i = 0;

  while (1) {
    char c = getchar();
    if (c == EOF) {
      break;
    }
    if (c == 'x') {
      i++;
    }
  }

  printf("%d\n", i);
  return 0;
}