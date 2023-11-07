#include <stdio.h>

double dot(size_t n, const double v[], const double w[]);

int main(void) {
  printf("%f\n", dot(6, (double[]){0.0783, 4.57, 13.1, -5.45, 9.60, 9.07},
                     (double[]){-5.85, 0.397, 2.11, 4.04, 2.20, -3.48}));

  return 0;
}