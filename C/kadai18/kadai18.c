#include <stdio.h>
// clang-format off
/* 関数の定義を修正 */
void fourArithmeticOperations(double* x, double* y, double* add, double* sub, double* mul, double* div){
  *add = *x + *y;
  *sub = *x - *y;
  *mul = *x * *y;
  *div = *x / *y;
};

int main(void){

  double a[2] = {0.0, 0.0};
  double add = 0.0;
  double sub = 0.0;
  double mul = 0.0;
  double div = 0.0;
  int i;

  for (i = 0; i < 2; i++)
      scanf("%lf", &a[i]);

  /* 四則演算の関数 */
  fourArithmeticOperations(&a[0], &a[1], &add, &sub, &mul, &div);

  printf("%lf\n %lf\n %lf\n %lf\n", add, sub, mul, div);
  return 0;
}