#include <stdio.h>

int fact(int x) {
  if (x == 0) {
    return 1;
  }
  return x * fact(x - 1);
}