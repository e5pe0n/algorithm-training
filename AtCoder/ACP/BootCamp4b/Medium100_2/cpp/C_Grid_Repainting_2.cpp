#include <bits/stdc++.h>
#define MAX_H 50
#define MAX_W 50
using namespace std;

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int H, W;
string S[MAX_H];

void solve() {
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        bool f = false;
        for (int k = 0; k < 4; ++k) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] == '#') {
            f = true;
            break;
          }
        }
        if (!f) {
          puts("No");
          return;
        }
      }
    }
  }
  puts("Yes");
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}