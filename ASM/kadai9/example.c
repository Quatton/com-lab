#include <stdio.h>

void mystrcat(char* s1, char* s2) {
  char *p1 = s1, *p2 = s2;

  while (*p1 != '\0') {
    p1++;
  }

  while (*p2 != '\0') {
    *p1 = *p2;
    p1++;
    p2++;
  }

  *p1 = '\0';
}