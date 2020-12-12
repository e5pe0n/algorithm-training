#include <bits/stdc++.h>
#define MAX_H 50
#define MAX_W 50
using namespace std;

int H, W;
string S[MAX_H];

void solve() {
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        continue;
      }
      int cnt = 0;
      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          int i2 = i + di;
          int j2 = j + dj;
          if (0 <= i2 && i2 < H && 0 <= j2 && j2 < W && S[i2][j2] == '#') {
            ++cnt;
          }
        }
      }
      S[i][j] = cnt + '0';
    }
  }
  for (int i = 0; i < H; ++i) {
    printf("%s\n", S[i].c_str());
  }
};

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}