#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int N = 100;
  int X = 0;

  for (int i = 0; i < N; i++) {
    float x = (float)rand() / (float)(RAND_MAX);
    float y = (float)rand() / (float)(RAND_MAX);

    if ((x * x + y * y) < 1) X++;
  }

  printf("%f\n", (float)(4 * X) / N);

  return 0;
}