#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, P;

map<ll, ll> prime_factorize() {
  map<ll, ll> res;
  for (ll i = 2; i * i <= P; ++i) {
    if (P % i != 0) {
      continue;
    }
    ll cnt = 0;
    while (P % i == 0) {
      P /= i;
      ++cnt;
    }
    res[i] = cnt;
  }
  if (P > 1) {
    res[P] = 1;
  }
  return res;
}

ll pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res *= x;
    }
    x *= x;
    n >>= 1;
  }
  return res;
}

void solve() {
  map<ll, ll> M = prime_factorize();
  ll res = 1;
  for (auto p : M) {
    if (p.second / N > 0) {
      res *= pow(p.first, p.second / N);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> P;
  solve();
}