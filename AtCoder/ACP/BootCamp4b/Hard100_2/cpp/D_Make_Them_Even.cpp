#include <bits/stdc++.h>
#define MAX_H 500
#define MAX_W 500
using namespace std;
typedef long long ll;

ll H, W;
ll A[MAX_H][MAX_W];

void solve() {
  vector<vector<ll>> res;
  for (ll i = 0; i < H; ++i) {
    if (i % 2 == 0) {
      for (ll j = 0; j < W; ++j) {
        if (A[i][j] % 2 == 0) { continue; }
        if (j + 1 < W) {
          ++A[i][j + 1];
          --A[i][j];
          res.push_back({i, j, i, j + 1});
        } else if (i + 1 < H) {
          ++A[i + 1][j];
          --A[i][j];
          res.push_back({i, j, i + 1, j});
        }
      }
    } else {
      for (ll j = W - 1; j >= 0; --j) {
        if (A[i][j] % 2 == 0) { continue; }
        if (j - 1 >= 0) {
          ++A[i][j - 1];
          --A[i][j];
          res.push_back({i, j, i, j - 1});
        } else if (i + 1 < H) {
          ++A[i + 1][j];
          --A[i][j];
          res.push_back({i, j, i + 1, j});
        }
      }
    }
  }
  ll N = res.size();
  printf("%lld\n", N);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < 4; ++j) {
      printf("%lld%c", res[i][j] + 1, j == 3 ? '\n' : ' ');
    }
  }
}

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  solve();
}