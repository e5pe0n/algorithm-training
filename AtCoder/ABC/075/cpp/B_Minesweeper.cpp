#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 50

using namespace std;

string S[MAX_H];

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.') {
        int cnt = 0;
        for (int _i = max(0, i - 1); _i < min(H, i + 2); ++_i) {
          for (int _j = max(0, j - 1); _j < min(W, j + 2); ++_j) {
            if (S[_i][_j] == '#') {
              ++cnt;
            }
          }
        }
        S[i][j] = cnt + '0';
      }
    }
  }
  for (int i = 0; i < H; ++i) {
    printf("%s\n", S[i].c_str());
  }
}