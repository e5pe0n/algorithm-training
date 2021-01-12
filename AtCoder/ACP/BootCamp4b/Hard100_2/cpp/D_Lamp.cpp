#include <bits/stdc++.h>
#define MAX_H 2'000
#define MAX_W 2'000
using namespace std;
typedef long long ll;

ll H, W;
string S[MAX_H];
ll C[MAX_H][MAX_W];

void solve() {
  for (ll i = 0; i < H; ++i) {
    ll left = 0;
    ll right = 0;
    while (right < W) {
      while (right < W && S[i][right] == '#') {
        ++right;
      }
      left = right;
      while (right < W && S[i][right] == '.') {
        ++right;
      }
      ll cnt = right - left;
      while (left < right) {
        C[i][left++] = cnt;
      }
    }
  }
  for (ll j = 0; j < W; ++j) {
    ll top = 0;
    ll bottom = 0;
    while (bottom < H) {
      while (bottom < H && S[bottom][j] == '#') {
        ++bottom;
      }
      top = bottom;
      while (bottom < H && S[bottom][j] == '.') {
        ++bottom;
      }
      ll cnt = bottom - top;
      while (top < bottom) {
        C[top++][j] += cnt;
      }
    }
  }
  ll res = 0;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      res = max(res, C[i][j] - 1);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}