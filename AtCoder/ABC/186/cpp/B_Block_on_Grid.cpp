#include <bits/stdc++.h>
#define MAX_H 100
#define MAX_W 100
#define MAX_A 100
using namespace std;
typedef long long ll;

ll H, W;
ll A[MAX_H][MAX_W];

void solve() {
  ll min_a = MAX_A;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      min_a = min(min_a, A[i][j]);
    }
  }
  ll res = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      res += max(0LL, A[i][j] - min_a);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  solve();
}