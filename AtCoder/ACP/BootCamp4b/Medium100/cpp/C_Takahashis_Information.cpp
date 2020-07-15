#include <iostream>
#include <stdio.h>

using namespace std;

int C[3][3];

int main() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> C[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    if (!((C[i][0] - C[(i + 1) % 3][0]) == (C[i][1] - C[(i + 1) % 3][1]) &&
          (C[i][1] - C[(i + 1) % 3][1]) == (C[i][2] - C[(i + 1) % 3][2]))) {
      printf("No\n");
      return 0;
    }
  }
  for (int j = 0; j < 3; ++j) {
    if (!((C[0][j] - C[0][(j + 1) % 3]) == (C[1][j] - C[1][(j + 1) % 3]) &&
          (C[1][j] - C[1][(j + 1) % 3]) == (C[2][j] - C[2][(j + 1) % 3]))) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}