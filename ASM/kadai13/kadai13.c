#include <stdio.h>

char* itoa10(int n, char* buf);

int debug(int n) {
  printf("debug: %d\n", n);
  return n;
}

char* debug_str(char* s) {
  printf("debug: %s\n", s);
  return s;
}

int main(void) {
  char buf[100];
  printf("%s\n", itoa10(123456789, buf));
  printf("%s\n", itoa10(-123456789, buf));
  printf("%s\n", itoa10(0, buf));
  printf("%s\n", itoa10(1, buf));
  printf("%s\n", itoa10(-1, buf));
  printf("%s\n", itoa10(123, buf));
  printf("%s\n", itoa10(-123, buf));
  printf("%s\n", itoa10(123456, buf));
  printf("%s\n", itoa10(-123456, buf));
  printf("%s\n", itoa10(123456789, buf));
  printf("%s\n", itoa10(-123456789, buf));
  printf("%s\n", itoa10(2147483647, buf));
  printf("%s\n", itoa10(-2147483648, buf));
  return 0;
}
