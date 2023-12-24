#include <stdio.h>

void str_copy(char *to, char *from) {
  char *pf = from, *pt = to;

  while (*pf != '\0') {
    *pt++ = *pf++;
  }

  *pt = '\0';
}

// clang-format off
int main(void){

  char a[100] = "Hello,world!";
  char b[100];

  /* 100文字以下の文字を入力 */
  scanf("%99s", b);

  str_copy(a, b);

  printf("%s\n", a);

  return 0;
}