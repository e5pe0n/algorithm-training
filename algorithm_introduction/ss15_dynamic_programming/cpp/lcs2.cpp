#include <stdio.h>

using namespace std;

int c[10][10]{};

void lcs_length(char *X, int X_length, char *Y, int Y_length) {
  for (int i = 1; i <= X_length; ++i) {
    for (int j = 1; j <= Y_length; ++j) {
      if (X[i - 1] == Y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
      } else {
        c[i][j] = c[i][j - 1];
      }
    }
  }
}

void print_lcs(int c[][10], char *X, int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (c[i][j - 1] > c[i - 1][j])
    print_lcs(c, X, i, j - 1);
  else if (c[i][j] == c[i - 1][j])
    print_lcs(c, X, i - 1, j);
  else {
    print_lcs(c, X, i - 1, j - 1);
    printf("%c, ", X[i - 1]);
  }
}

int main() {
  char X[]{'A', 'B', 'C', 'B', 'D', 'A', 'B'};
  char Y[]{'B', 'D', 'C', 'A', 'B', 'A'};

  int X_length = sizeof(X) / sizeof(X[0]);
  int Y_length = sizeof(Y) / sizeof(Y[0]);

  lcs_length(X, X_length, Y, Y_length);
  print_lcs(c, X, X_length, Y_length); // B, C, B, A,
  printf("\n");
}