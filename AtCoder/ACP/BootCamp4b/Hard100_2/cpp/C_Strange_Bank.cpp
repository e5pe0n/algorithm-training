#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  ll res = N;
  for (ll i = 0; i <= N; ++i) {
    ll x = 0;
    ll t = i;
    while (t > 0) {
      x += t % 6;
      t /= 6;
    }
    t = N - i;
    while (t > 0) {
      x += t % 9;
      t /= 9;
    }
    res = min(res, x);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}