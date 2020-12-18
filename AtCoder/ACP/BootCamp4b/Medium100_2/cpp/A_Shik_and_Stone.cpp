#include <bits/stdc++.h>
#define MAX_H 8
using namespace std;

int H, W;
string A[MAX_H];

void solve() {
  int i = 0;
  int j = 0;
  A[i][j] = '.';
  while (i != H - 1 || j != W - 1) {
    bool f = false;
    while (j + 1 < W && A[i][j + 1] == '#') {
      ++j;
      A[i][j] = '.';
      f = true;
    }
    if (i + 1 < H && A[i + 1][j] == '#') {
      ++i;
      A[i][j] = '.';
      f = true;
    }
    if (!f) {
      puts("Impossible");
      return;
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == '#') {
        puts("Impossible");
        return;
      }
    }
  }
  puts("Possible");
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
  }
  solve();
}