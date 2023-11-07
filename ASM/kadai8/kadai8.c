#include <stdio.h>

int maxof2(int x, int y);
int maxof3(int x, int y, int z);

int main() {
  int x = 1;
  int y = 2;
  int z = 3;

  printf("maxof2(%d, %d): %d\n", x, y, maxof2(x, y));
  printf("maxof3(%d, %d, %d): %d\n", x, y, z, maxof3(x, y, z));
}