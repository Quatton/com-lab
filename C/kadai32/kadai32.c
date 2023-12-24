#include <stdio.h>

int main() {
  FILE* fptr;
  FILE* outptr;

  char o[100] = "";
  scanf("%[^\n]s", o);

  char buffer[100];
  fptr = fopen("./test.txt", "r");

  float sum = 0;
  int count = 0;

  while (fgets(buffer, 100, fptr)) {
    int i;
    sscanf(buffer, "%d", &i);
    sum += i;
    count++;
  }

  // printf("%f", sum / count);

  outptr = fopen(o, "w");

  char out[20];
  sprintf(out, "%f", sum / count);
  fprintf(outptr, out);

  fclose(fptr);
}