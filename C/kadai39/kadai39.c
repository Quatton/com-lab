#include <stdio.h>
#include <string.h>

int comperm(char* str1, char* str2) {
  if (strlen(str1) != strlen(str2)) {
    return 0;
  }

  char hash_map[256] = {0};
  char* reader = str1;

  while (*reader != '\0') {
    hash_map[(int)*reader]++;
    reader++;
  }

  reader = str2;
  while (*reader != '\0') {
    hash_map[(int)*reader]--;
    reader++;
  }

  for (int i = 0; i < 256; i++) {
    if (hash_map[i] != 0) {
      return 0;
    }
  }

  return 1;
}

int main(void) {
  // abcde
  // edabc

  char str1[100], str2[100];

  scanf("%s %s", str1, str2);

  printf("%s\n", comperm(str1, str2) ? "OK" : "NG");
}