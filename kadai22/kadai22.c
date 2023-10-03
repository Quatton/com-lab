#include <stdio.h>

// clang-format off
int main(void){

  char name[] = "Hello,world!";
  char *p;

  // clang-format on
  /* ここを埋める。 */
  p = name;
  while (*p != '\0') {
    printf("%c\n", *p);
    p++;
  }
  // clang-format off

  return 0;
}