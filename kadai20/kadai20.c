#include <stdio.h>

void set_idx(int* a, int n) {
  int* p = a;
  int i = 0;
  while (i < n) {
    *p = i;
    i++;
    p++;
  }
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