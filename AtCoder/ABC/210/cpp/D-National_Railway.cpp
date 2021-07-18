#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_H = 1000;
const ll MAX_W = 1000;
const ll INF = 1e18;
ll H, W, C;
ll A[MAX_H][MAX_W];
ll dp[MAX_H + 1][MAX_W + 1];
ll X[MAX_H + 1][MAX_W + 1];

int main() {
  cin >> H >> W >> C;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  ll res = INF;
  for (ll _ = 0; _ < 2; ++_) {
    for (ll i = 0; i <= H; ++i) {
      fill(dp[i], dp[i] + W + 1, INF);
    }
    for (ll i = 1; i <= H; ++i) {
      for (ll j = 1; j <= W; ++j) {
        dp[i][j] = min({A[i - 1][j - 1], dp[i - 1][j] + C, dp[i][j - 1] + C});
      }
    }
    for (ll i = 1; i <= H; ++i) {
      for (ll j = 1; j <= W; ++j) {
        X[i][j] = min(dp[i - 1][j] + A[i - 1][j - 1] + C,
                      dp[i][j - 1] + A[i - 1][j - 1] + C);
        res = min(res, X[i][j]);
      }
    }
    for (ll i = 0; i < H; ++i) {
      reverse(A[i], A[i] + W);
    }
  }
  printf("%lld\n", res);
}