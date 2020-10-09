#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 50
#define MAX_W 50
#define INF 1'000'000'000

using namespace std;

string S[MAX_H]{};
int D[MAX_H][MAX_W]{};

int at(int i, int j, int H, int W) {
  if (0 <= i && i < H && 0 <= j && j < W && S[i][j] == '.') {
    return D[i][j];
  } else {
    return INF;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  int black = 0;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        ++black;
      }
      D[i][j] = INF;
    }
  }
  D[0][0] = 1;
  for (int _ = 0; _ < H * W; ++_) {
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (S[i][j] == '.') {
          int up = at(i - 1, j, H, W);
          int low = at(i + 1, j, H, W);
          int left = at(i, j - 1, H, W);
          int right = at(i, j + 1, H, W);
          D[i][j] = min(D[i][j], min(up + 1, min(low + 1, min(left + 1, right + 1))));
        }
      }
    }
  }
  int ans = -1;
  int white = D[H - 1][W - 1];
  if (white < INF) {
    ans = H * W - black - white;
  }
  printf("%d\n", ans);
}
