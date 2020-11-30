#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

map<ll, ll> prime_factorize(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      ++res[i];
    }
  }
  if (n > 1) {
    ++res[n];
  }
  return res;
}

void solve() {
  map<ll, ll> m = prime_factorize(N);
  ll res = 0;
  for (auto _m : m) {
    ll v = _m.first;
    ll cnt = _m.second;
    ll lb = 0;
    ll ub = cnt + 1;
    while (ub - lb > 1) {
      ll md = (lb + ub) / 2;
      if (md * (md + 1) / 2 <= cnt) {
        lb = md;
      } else {
        ub = md;
      }
    }
    res += lb;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}