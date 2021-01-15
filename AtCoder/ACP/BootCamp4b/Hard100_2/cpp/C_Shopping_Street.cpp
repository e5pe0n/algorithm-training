#include <bits/stdc++.h>
#define INF 1'000'000'000'000'000'000
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
bool F[MAX_N][10];
ll P[MAX_N][11];

void solve() {
  ll res = -INF;
  for (ll i = 1; i < 1 << 10; ++i) {
    ll t = 0;
    for (ll k = 0; k < N; ++k) {
      ll c = 0;
      for (ll j = 0; j < 10; ++j) {
        c += (i >> j & 1) && F[k][j];
      }
      t += P[k][c];
    }
    res = max(res, t);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < 10; ++j) {
      cin >> F[i][j];
    }
  }
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j <= 10; ++j) {
      cin >> P[i][j];
    }
  }
  solve();
}