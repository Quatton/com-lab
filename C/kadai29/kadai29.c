#include <stdio.h>

// clang-format off
struct complex_number {
  double real;
  double imaginary;
};
// clang-format on

struct complex_number complex_number_add(struct complex_number a,
                                         struct complex_number b) {
  struct complex_number c = {a.real + b.real, a.imaginary + b.imaginary};
  return c;
}

struct complex_number complex_number_multiply(struct complex_number a,
                                              struct complex_number b) {
  struct complex_number c = {a.real * b.real - a.imaginary * b.imaginary,
                             a.real * b.imaginary + a.imaginary * b.real};
  return c;
}

// clang-format off
int main(void){

  struct complex_number a, b, c, d;
  scanf("%lf %lf", &a.real, &a.imaginary);
  scanf("%lf %lf", &b.real, &b.imaginary);

  c = complex_number_add(a, b);
  d = complex_number_multiply(a, b);

  printf("%lf %lf\n", c.real, c.imaginary);
  printf("%lf %lf\n", d.real, d.imaginary);

  return 0;
}