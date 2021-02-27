#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> prime_factorize(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n > 1) res[n] = 1;
  return res;
}

set<ll> gen_prime_5_mod_6(ll n) {
  set<ll> res;
  res.insert(11);
  while (*(--res.end()) < n) {
    ll A = 1;
    for (auto v : res)
      A *= v;
    A += 5;
    map<ll, ll> ps = prime_factorize(A);
    if (ps.size() == 1) res.insert(ps.begin()->first);
    for (auto p : ps) {
      ll x = p.first;
      if (x % 6 == 5) res.insert(x);
    }
  }
  return res;
}

int main() {
  set<ll> ps = gen_prime_5_mod_6(1000);
  for (auto it = ps.begin(); it != ps.end(); ++it) {
    printf("%lld%c", *it, it == --ps.end() ? '\n' : ' ');
  }
  // 2 3 11 71 4691
}