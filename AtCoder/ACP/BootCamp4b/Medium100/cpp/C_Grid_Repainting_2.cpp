#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 50

using namespace std;

char C[MAX_H][MAX_H];

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    string S;
    cin >> S;
    for (int j = 0; j < W; ++j) {
      C[i][j] = S[j];
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (C[i][j] == '#') {
        int cnt = 0;
        if (i - 1 >= 0 && C[i - 1][j] == '#') {
          ++cnt;
        }
        if (i + 1 < H && C[i + 1][j] == '#') {
          ++cnt;
        }
        if (j - 1 >= 0 && C[i][j - 1] == '#') {
          ++cnt;
        }
        if (j + 1 < W && C[i][j + 1] == '#') {
          ++cnt;
        }
        if (cnt == 0) {
          printf("No\n");
          return 0;
        }
      }
    }
  }
  printf("Yes\n");
}