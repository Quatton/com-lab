#include <stdio.h>
#include <stdlib.h>

int longer(char* a, char* b) {
  char* pa = a;
  char* pb = b;

  while (*pa != '\0' && *pb != '\0') {
    pa++;
    pb++;
  }

  if (*pa == '\0' && *pb == '\0') {
    return 0;
  } else if (*pa == '\0') {
    return -1;
  } else {
    return 1;
  }
}

int numlen(int n) {
  int len = 0;
  while (n > 0) {
    n /= 10;
    len++;
  }
  return len;
}

int main(void) {
  // AAAATTCCCCTGG
  // A4T2C4T1G2

  char input[100];
  char output[200];

  scanf("%s", input);
  // sprintf(input, "ATCG");

  char* p = input;
  char* q = output;

  char counting = *p;
  int count = 0;
  while (*p != '\0') {
    if (*p == counting) {
      count++;
    } else {
      *q = counting;
      q++;
      sprintf(q, "%d", count);
      q += numlen(count);
      counting = *p;
      count = 1;
    }
    p++;
  }
  *q = counting;
  q++;
  sprintf(q, "%d", count);
  q += numlen(count);
  counting = *p;
  count = 1;
  *q = '\0';

  if (longer(input, output) <= 0) {
    sprintf(output, "%s", input);
  }

  printf("%s\n", output);
}