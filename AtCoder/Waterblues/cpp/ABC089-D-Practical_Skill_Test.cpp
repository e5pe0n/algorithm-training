#include <bits/stdc++.h>
#define MAX_H 300
#define MAX_W 300
#define MAX_HW MAX_H *MAX_W
#define MAX_Q 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll H, W, D;
ll A[MAX_H][MAX_W];
pll B[MAX_HW + 1];
vector<vector<ll>> V;
ll Q;

int main() {
  cin >> H >> W >> D;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      B[A[i][j]] = {i, j};
    }
  }
  V = vector<vector<ll>>(D);
  for (ll i = 0; i < D; ++i) {
    V[i].push_back(0);
    if (i == 0) V[i].push_back(0);
    ll sum = 0;
    for (ll j = i == 0 ? D : i; j + D <= H * W; j += D) {
      auto [x, y] = B[j];
      auto [_x, _y] = B[j + D];
      sum += abs(_x - x) + abs(_y - y);
      V[i].push_back(sum);
    }
  }
  cin >> Q;
  for (ll i = 0; i < Q; ++i) {
    ll L, R;
    cin >> L >> R;
    ll res = V[R % D][R / D] - V[L % D][L / D];
    printf("%lld\n", res);
  }
}