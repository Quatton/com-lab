#include <stdio.h>
#include <stdlib.h>

void copy(char* to, char* from) {
  while (*from != '\0') {
    *to = *from;
    to++;
    from++;
  }
  *to = '\0';
}

int eq_len(char* a, char* b) {
  char* pa = a;
  char* pb = b;

  while (*pa != '\0' || *pb != '\0') {
    if (*pa == '\0' || *pb == '\0') {
      return 0;
    }

    pa++;
    pb++;
  }
  return 1;
}

int exists_and_pop(char* s, char c) {
  char* p = s;
  while (*p != '\0') {
    if (*p == c) {
      *p = '\\';  // it's not very cool to abuse the fact that '\' is not in the
                  // alphabet and probably not in testcase
      return 1;
    }
    p++;
  }
  return 0;
}

int comperm(char* s1, char* s2) {
  if (!eq_len(s1, s2)) {
    return 0;
  }
  char* p1 = s1;

  char* cop = calloc(100, sizeof(char));
  copy(cop, s2);
  while (*p1 != '\0') {
    if (!exists_and_pop(cop, *p1)) {
      return 0;
    }
    p1++;
  }
  free(cop);
  return 1;
}

int main(void) {
  // abcde
  // edabc
  // if we go from left to right, this will be O(n^2)
  // it's fine let's do it

  char str1[100], str2[100];

  scanf("%s %s", str1, str2);

  printf("%s\n", comperm(str1, str2) ? "OK" : "NG");
}