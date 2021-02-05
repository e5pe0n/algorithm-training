#include <bits/stdc++.h>
#define MAX_N 15
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<pll> A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    for (ll j = 0; j < a; ++j) {
      ll x, y;
      cin >> x >> y;
      A[i].push_back({x - 1, y});
    }
  }
  ll res = 0;
  for (ll i = 0; i < (1 << N); ++i) {
    bool f = true;
    ll cnt = 0;
    for (ll j = 0; j < N; ++j) {
      if (i >> j & 1) {
        ++cnt;
        for (auto p : A[j]) {
          ll x = p.first;
          ll y = p.second;
          if ((i >> x & 1) != y) f = false;
        }
      }
    }
    if (f) res = max(res, cnt);
  }
  printf("%lld\n", res);
}