#include <stdio.h>

int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  float percent = (float)a / (float)b * 100;
  printf("%.2f\n", percent);
}