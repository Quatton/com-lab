#include <stdio.h>

int mystrcmp(char* s1, char* s2) {
  char *p1 = s1, *p2 = s2;

  while (*p1 != '\0' || *p2 != '\0') {
    if (*p1 != *p2 || *p1 == '\0' || *p2 == '\0') {
      return *p1 - *p2;
    }
    p1++;
    p2++;
  }

  return 0;
}