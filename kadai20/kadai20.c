#include <stdio.h>

void set_idx(int* a, int n) {
  for (int i = 0; i < n; i++) *(a + i) = i;
}

// clang-format off
int main(void){

  int a[5];
  int i;

  set_idx(a, 5);

  for (i = 0; i < 5; i++)
      printf("%d\n", a[i]);

  return 0;
}