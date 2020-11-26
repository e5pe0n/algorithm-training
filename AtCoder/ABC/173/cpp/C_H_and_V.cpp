#include <bits/stdc++.h>
#define MAX_H 6
#define MAX_W 6
using namespace std;

int H, W, K;
string C[MAX_H];
string _C[MAX_H];
bool BH[MAX_H], BW[MAX_W];

void solve() {
  int res = 0;
  for (int h = 0; h <= H; ++h) {
    memset(BH, false, H);
    for (int i = 0; i < h; ++i) {
      BH[i] = true;
    }
    do {
      for (int w = 0; w <= W; ++w) {
        memset(BW, false, W);
        for (int j = 0; j < w; ++j) {
          BW[j] = true;
        }
        do {
          for (int i = 0; i < H; ++i) {
            _C[i] = C[i];
          }
          for (int i = 0; i < H; ++i) {
            if (BH[i]) {
              for (int j = 0; j < W; ++j) {
                _C[i][j] = 'R';
              }
            }
          }
          for (int j = 0; j < W; ++j) {
            if (BW[j]) {
              for (int i = 0; i < H; ++i) {
                _C[i][j] = 'R';
              }
            }
          }
          int cnt = 0;
          for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
              if (_C[i][j] == '#') {
                ++cnt;
              }
            }
          }
          if (cnt == K) {
            ++res;
          }
        } while (prev_permutation(BW, BW + W));
      }
    } while (prev_permutation(BH, BH + H));
  }
  printf("%d\n", res);
}

int main() {
  cin >> H >> W >> K;
  for (int i = 0; i < H; ++i) {
    cin >> C[i];
  }
  solve();
}