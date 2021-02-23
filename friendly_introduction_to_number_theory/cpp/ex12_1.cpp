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
  if (n > 1) ++res[n];
  return res;
}

set<ll> gen_primes(ll n) {
  set<ll> st;
  st.insert(5);
  while (*(--st.end()) < n) {
    ll A = 1;
    for (auto v : st) {
      A *= v;
    }
    A += 1;
    map<ll, ll> ps = prime_factorize(A);
    for (auto p : ps) {
      st.insert(p.first);
    }
  }
  return st;
}

int main() {
  set<ll> ps = gen_primes(1000);
  for (auto it = ps.begin(); it != ps.end(); ++it) {
    printf("%lld%c", *it, it == --ps.end() ? '\n' : ' ');
  }
  // 2 3 5 7 19 31 37 3343
}