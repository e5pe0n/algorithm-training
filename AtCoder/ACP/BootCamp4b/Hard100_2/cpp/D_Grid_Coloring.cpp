#include <bits/stdc++.h>
#define MAX_N 10000
#define MAX_H 100
#define MAX_W 100
using namespace std;

int H, W, N;
int A[MAX_N];
int C[MAX_H][MAX_W];

void solve() {
  int idx = 0;
  for (int i = 0; i < H; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; ++j) {
        C[i][j] = idx;
        if (--A[idx] <= 0) {
          ++idx;
        }
      }
    } else {
      for (int j = W - 1; j >= 0; --j) {
        C[i][j] = idx;
        if (--A[idx] <= 0) {
          ++idx;
        }
      }
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      printf("%d%c", C[i][j] + 1, j == W - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  cin >> H >> W >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}