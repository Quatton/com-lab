#include <stdio.h>

int max_of(int* a, int n) {
  int max = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

// clang-format off
int main(void){

  int a[5] = {0, 0, 0, 0, 0};
  int i, max;

  for (i = 0; i < 5; i++)
      scanf("%d", &a[i]);

  max = max_of(a, 5);
  printf("%d\n", max);

  return 0;
}