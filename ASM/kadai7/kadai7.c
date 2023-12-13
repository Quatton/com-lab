#include <stdio.h>

int mystrcmp(char* s1, char* s2);

int main() {
  int res1 = mystrcmp("app", "apple");

  int res2 = mystrcmp("pine", "apple");

  int res3 = mystrcmp("foo\0bar", "foo");

  printf("res1: %d, res2: %d, res3: %d\n", res1<0, res2> 0, res3 == 0);
}