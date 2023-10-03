#include <stdio.h>

int main() {
  int a;
  int b = 1;
  scanf("%d", &a);

  while (1) {
    if (b > a) {
      break;
    }
    printf("%d ", b);
    b = 2 * b;
  }
}