#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_H = 2000;
const ll MAX_W = 2000;
ll H, W;
ll A[MAX_H][MAX_W];
ll R[MAX_H];
ll C[MAX_W];

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      R[i] += A[i][j];
      C[j] += A[i][j];
    }
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      printf("%lld%c", R[i] + C[j] - A[i][j], j == W - 1 ? '\n' : ' ');
    }
  }
}