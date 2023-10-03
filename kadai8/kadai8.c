#include <stdio.h>

int main() {
  int x;

  scanf("%d", &x);

  for (int i = x; i >= 1; i--) {
    // space
    for (int j = 0; j < x - i; j++) {
      printf(" ");
    }

    // *
    for (int j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }

    printf("\n");
  }
}