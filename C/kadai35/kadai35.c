#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int N = 10000;
  int X = 0;

  srand((unsigned int)time(NULL) + rand());

  for (int i = 0; i < N; i++) {
    float x = (float)rand() / RAND_MAX;
    float y = (float)rand() / RAND_MAX;

    float d = x * x + y * y;
    // check d

    if (d < 1) X++;
  }

  printf("%f\n", (float)(4 * X) / N);

  return 0;
}