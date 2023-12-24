#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// courtesy of https://en.wikipedia.org/wiki/Longest_common_subsequence
// Prefix S_n
// is defined as the first n characters of S
// S = "ABCD"
// S_0 = ""
// S_1 = "A"
// S_2 = "AB"
// yeah you get the idea

// If we have LCS which is a function that computes the longest common
// subsequence of two strings, then LCS(X^A, Y^A) = LCS(X, Y)^A; A is a symbol,
// ^ means concatenation

// and
// LCS(X^A, Y^B) = max({ LCS(X, Y^B), LCS(X^A, Y) | X, Y are strings, A, B are
// symbols }) meaning if we were to add more symbols to the end of the strings
// if those symbols happen to not be the same, then there is no point
// considering the case where both symbols contribute to the LCS

// therefore
// LCS(X_i, Y_j) = empty string          if i = 0 or j = 0
//               = LCS(X_i-1, Y_j-1)^x_i if x_i = y_j
//               = max({ LCS(X_i-1, Y_j), LCS(X_i, Y_j-1) }) if and x_i
//               != y_j

typedef struct _Coord {
  int x;
  int y;
  char val;
  int len;
} Coord;

void LCS(char* x, char* y, int i, int j, Coord*** table) {
  Coord* coord = calloc(1, sizeof(Coord));
  if (i == 0 || j == 0) {
    coord->val = '\0';
    coord->len = 0;
    table[i][j] = coord;
  }

  if (x[i] == y[j]) {
    coord->val = x[i];
    coord->x = i - 1;
    coord->y = j - 1;
    coord->len = (table[i - 1][j - 1])->len + 1;
    return;
  }

  if (x[i] != y[j]) {
    coord->val = '\0';

    if ((table[i - 1][j])->len > (table[i][j - 1])->len) {
      coord->x = i - 1;
      coord->y = j;
      coord->len = (table[i - 1][j])->len;
      return;
    } else {
      coord->x = i;
      coord->y = j - 1;
      coord->len = (table[i][j - 1])->len;
      return;
    }
  }
}

int main() {
  char* x = "ABCBDAB";
  char* y = "BDCABA";

  int x_len = strlen(x);
  int y_len = strlen(y);

  Coord*** table = calloc(x_len + 1, sizeof(Coord**));

  for (int i = 0; i < x_len + 1; i++) {
    table[i] = calloc(y_len + 1, sizeof(Coord*));
  }
}