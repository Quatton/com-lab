#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  int i;

  for (i = 0; i < 5; i++) {
    srand((unsigned int)time(NULL) + rand());
    printf("%d\n", rand() % 100);
  }

  return 0;
}