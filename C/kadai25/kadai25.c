#include <stdio.h>

void rev_string(char* s) {
  char* pt = s;
  char* ps = s;
  int until = 0;

  // idk how to move a pointer to the end
  while (*pt != '\0') {
    pt++;
    until++;
  }

  // _ _ _ _ _ pt

  // back 1 step
  pt--;

  until = until / 2;

  // _ _ _ _ pt
  // ps _ _ _ _

  while (until != 0) {
    char temp = *pt;
    *pt = *ps;
    *ps = temp;
    ps++;
    pt--;
    until--;
  }
}

// clang-format off
int main(void){

  char s[100] = "";

  scanf("%99s", s);
  rev_string(s);

  printf("%s\n", s);

  return 0;
}