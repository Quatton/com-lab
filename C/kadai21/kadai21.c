#include <stdio.h>

void ary_set(int *a, int x, int n) {
  for (int i = 0; i < n; i++) {
    *(a + i) = x;
  }
}

// clang-format off
int main(void){

  int i;
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n;

  scanf("%d", &n);

  ary_set(a, -1, n);

  for (i = 0; i < 10; i++) 
  printf("%d\n", a[i]);
  return 0;
}