#include <bits/stdc++.h>
#define MAX_N 15
using namespace std;
typedef long long ll;

ll N;
vector<ll> X[MAX_N];
vector<ll> Y[MAX_N];

void solve() {
  ll res = 0;
  for (ll i = 0; i < 1 << N; ++i) {
    bool f = true;
    ll cnt = 0;
    for (ll j = 0; j < N; ++j) {
      if (!(i >> j & 1)) continue;
      ++cnt;
      for (ll k = 0; k < X[j].size(); ++k) {
        ll x = X[j][k];
        ll y = Y[j][k];
        if ((i >> x & 1) != y) {
          f = false;
          break;
        }
      }
    }
    if (f) { res = max(res, cnt); }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    X[i] = vector<ll>(a);
    Y[i] = vector<ll>(a);
    for (ll j = 0; j < a; ++j) {
      cin >> X[i][j] >> Y[i][j];
      --X[i][j];
    }
  }
  solve();
}