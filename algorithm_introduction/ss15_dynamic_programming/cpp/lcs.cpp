#include <stdio.h>

using namespace std;

enum Direction {
  UP,
  LEFT,
  UPLEFT,
};

int c[10][10]{};
int b[10][10]{};

void lcs_length(char *X, int X_length, char *Y, int Y_length) {
  for (int i = 1; i <= X_length; ++i) {
    for (int j = 1; j <= Y_length; ++j) {
      if (X[i - 1] == Y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = Direction::UPLEFT;
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
        b[i][j] = Direction::UP;
      } else {
        c[i][j] = c[i][j - 1];
        b[i][j] = Direction::LEFT;
      }
    }
  }
}

void print_lcs(int b[][10], char *X, int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == Direction::UPLEFT) {
    print_lcs(b, X, i - 1, j - 1);
    printf("%c, ", X[i - 1]);
  } else if (b[i][j] == Direction::UP) {
    print_lcs(b, X, i - 1, j);
  } else {
    print_lcs(b, X, i, j - 1);
  }
}

int main() {
  char X[]{'A', 'B', 'C', 'B', 'D', 'A', 'B'};
  char Y[]{'B', 'D', 'C', 'A', 'B', 'A'};

  int X_length = sizeof(X) / sizeof(X[0]);
  int Y_length = sizeof(Y) / sizeof(Y[0]);

  lcs_length(X, X_length, Y, Y_length);
  print_lcs(b, X, X_length, Y_length); // B, C, B, A,
  printf("\n");
}