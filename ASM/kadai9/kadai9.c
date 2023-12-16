#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char* s);
void mystrcpy(char* s1, char* s2);

char* mystrcat(char* dest, char* src);

int main() {
  char s[50] = "123456";
  char s2[50] = "789";

  int pass1 = mystrlen(s);

  strcat(s, s2);
  int pass3 = mystrlen(s);

  printf("pass1: %d, expected: %d\n", pass1, 6);
  printf("pass2: %s, expected: %s\n", s, "123456789");
  printf("pass3: %d, expected: %d\n", pass3, 9);
}