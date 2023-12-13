#include <stdio.h>

void str_toupper(char* s) {
  char* p = s;

  while (*p != '\0') {
    if (*p >= 97 && *p <= 122) {
      *p -= 32;
    }

    p++;
  }
}

// clang-format off
int main(void){

  char s[100] = "";
  scanf("%99s", s);

  str_toupper(s);

  printf("%s\n", s);

  return 0;
}