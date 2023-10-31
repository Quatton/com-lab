#include <stdio.h>

int str_chnum(char* s, int c) {
  char* p = s;
  int count = 0;
  while (*p != '\0') {
    if (*p == 'a') count++;
    p++;
  }
  return count;
}

// clang-format off
int main(void){

  char s[100] = "";
  int c = 'a';

  scanf("%99s", s);

  printf("%d\n", str_chnum(s, c));

  return 0;
}