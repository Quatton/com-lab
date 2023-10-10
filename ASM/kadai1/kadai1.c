#include <stdio.h>

void convert_to_base2(int dec) {
  // 1u = unsigned 1
  // << 31 = leftshift to left-most position
  // bit >>= 1 incrementally right-shift
  for (unsigned bit = 1u << 31; bit != 0; bit >>= 1) {
    // this and will test correspondence of the bit to the each binary digit of
    // the decimal
    // basically bit is always 1 but just shifting
    putchar((dec & bit) ? '1' : '0');
  }
  printf("\n");
}

int main() {
  int dec;

  scanf("%d", &dec);

  convert_to_base2(dec);
}