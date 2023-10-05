#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *src1 = "Hello,world!";
  char *src2 = calloc(strlen(src1) + 1, sizeof(char));

  if (src2 == NULL) {
    exit(1);
  }
  strcpy(src2, src1);

  printf("%s\n", src2);

  free(src2);
  return 0;
}