#include <stdio.h>

int main(void) {
  int matA[2][3];
  int matB[3][2];

  for (int i = 0; i < 2; i++)
    scanf("%d %d %d", &matA[i][0], &matA[i][1], &matA[i][2]);
  for (int i = 0; i < 3; i++) scanf("%d %d", &matB[i][0], &matB[i][1]);

  int prod[2][2] = {0};

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) prod[i][j] += matA[i][k] * matB[k][j];
    }

  printf("%d %d\n%d %d\n", prod[0][0], prod[0][1], prod[1][0], prod[1][1]);
}