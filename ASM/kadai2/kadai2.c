#include <stdio.h>

void convert_to_base2(float dec) {
  int *d = (int *)&dec;
  // 1u = unsigned 1
  // << 31 = leftshift to left-most position
  // bit >>= 1 incrementally right-shift
  for (unsigned bit = 1u << 31; bit != 0; bit >>= 1) {
    // this and will test correspondence of the bit to the each binary digit of
    // the decimal
    // basically bit is always 1 but just shifting
    putchar((*d & bit) ? '1' : '0');
  }
  printf("\n");
}

int main() {
  // 1 sign bit | 8 exponent bit | 23 fraction bits

  float dec;

  scanf("%e", &dec);

  convert_to_base2(dec);
}