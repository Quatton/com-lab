#include <stdio.h>
#include <string.h>

int main() {
  int a;
  scanf("%d", &a);

  char str[100];  // probably enough
  sprintf(str, "%d", a);

  int len = strlen(str);
  int zeroOk = 0;
  for (int i = 0; i < len; i++) {
    if (str[len - 1 - i] == '0' && !zeroOk) {
      continue;
    }
    zeroOk = 1;
    printf("%c", str[len - 1 - i]);
  }
}