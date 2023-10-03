#include <stdio.h>

// from kadai27
void str_copy(char* to, char* from) {
  char *pf = from, *pt = to;

  while (*pf != '\0') {
    *pt++ = *pf++;
  }

  *pt = '\0';
}

// from kadai25
void reverse(char s[][10], int n) {
  char(*pt)[10] = s + n - 1;
  char(*ps)[10] = s;
  int until = n / 2;

  while (until != 0) {
    char temp[10] = "";
    str_copy(temp, *pt);
    str_copy(*pt, *ps);
    str_copy(*ps, temp);
    ps++;
    pt--;
    until--;
  }
}

// clang-format off
int main(void) {

  char a[5][10] = {"", "", "", "", ""};
  int i;

  for (i = 0; i < 5; i++)
      scanf("%9s", a[i]);

  reverse(a, 5);

  for (i = 0; i < 5; i++)
      printf("%s\n", a[i]);

  return 0;
}