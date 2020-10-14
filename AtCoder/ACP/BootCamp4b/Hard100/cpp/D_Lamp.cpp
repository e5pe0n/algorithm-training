#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 2000
#define MAX_W 2000

using namespace std;

string S[MAX_H];
int C[MAX_H][MAX_W]{};

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  for (int i = 0; i < H; ++i) {
    int left = 0;
    int right = 0;
    while (right < W) {
      while (right < W && S[i][right] == '.') {
        ++right;
      }
      for (int j = left; j < right; ++j) {
        C[i][j] = right - left;
      }
      while (right < W && S[i][right] == '#') {
        ++right;
      }
      left = right;
    }
  }
  for (int j = 0; j < W; ++j) {
    int top = 0;
    int bottom = 0;
    while (bottom < H) {
      while (bottom < H && S[bottom][j] == '.') {
        ++bottom;
      }
      for (int i = top; i < bottom; ++i) {
        C[i][j] += bottom - top;
      }
      while (bottom < H && S[bottom][j] == '#') {
        ++bottom;
      }
      top = bottom;
    }
  }
  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      ans = max(ans, C[i][j] - 1);
    }
  }
  printf("%d\n", ans);
}