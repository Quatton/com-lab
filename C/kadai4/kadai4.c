#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if (a == b && b == c && c == a) {
    printf("3");
  } else if (a == b || b == c || c == a) {
    printf("2");
  } else {
    printf("1");
  }
}