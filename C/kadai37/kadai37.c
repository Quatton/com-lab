#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int is_prime(int x) {
  for (int i = 2; i <= x / 2; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

int main(void) {
  unsigned int X = 0;

  scanf("%d", &X);

  for (int n = 2; n <= X; n++) {
    if (is_prime(n)) {
      printf("%d\n", n);
    }
  }
}