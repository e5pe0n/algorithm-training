#include <bits/stdc++.h>
#define MAX_H 100
using namespace std;

int H, W;
string A[MAX_H];

void solve() {
  set<int> st_h;
  set<int> st_w;
  for (int i = 0; i < H; ++i) {
    bool f = true;
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == '#') {
        f = false;
        break;
      }
    }
    if (f) {
      st_h.insert(i);
    }
  }
  for (int j = 0; j < W; ++j) {
    bool f = true;
    for (int i = 0; i < H; ++i) {
      if (A[i][j] == '#') {
        f = false;
        break;
      }
    }
    if (f) {
      st_w.insert(j);
    }
  }
  for (int i = 0; i < H; ++i) {
    auto fh = st_h.find(i);
    for (int j = 0; j < W; ++j) {
      auto fw = st_w.find(j);
      if (fh == st_h.end() && fw == st_w.end()) {
        printf("%c", A[i][j]);
      }
    }
    if (fh == st_h.end()) {
      printf("\n");
    }
  }
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
  }
  solve();
}