#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 100

using namespace std;

string S[MAX_H];
int C[MAX_H][MAX_H]{};

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (i - 1 >= 0 && j - 1 >= 0) {
        C[i][j] = min(C[i - 1][j] + (S[i - 1][j] == '.' && S[i][j] == '#'),
                      C[i][j - 1] + (S[i][j - 1] == '.' && S[i][j] == '#'));
      } else if (i - 1 >= 0) {
        C[i][j] = C[i - 1][j] + (S[i - 1][j] == '.' && S[i][j] == '#');
      } else if (j - 1 >= 0) {
        C[i][j] = C[i][j - 1] + (S[i][j - 1] == '.' && S[i][j] == '#');
      } else {
        C[i][j] = S[i][j] == '#';
      }
    }
  }

  printf("%d\n", C[H - 1][W - 1]);
}