#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> gen_primes(ll n) {
  vector<ll> primes;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (ll j = i + i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

vector<ll> gen_CRs(ll n) {
  ll b = 0;
  for (ll i = 0; i < n; ++i) {
    b |= 1 << (i * i * i % n);
  }
  vector<ll> crs;
  for (ll i = 0; i < n; ++i) {
    if (b & (1 << i)) crs.push_back(i);
  }
  return crs;
}

int main() {
  vector<ll> ps = gen_primes(30);
  vector<ll> _ps;
  for (auto p : ps) {
    if (p % 3 == 2) _ps.push_back(p);
  }
  for (auto p : _ps) {
    vector<ll> crs = gen_CRs(p);
    printf("%lld: ", p);
    for (ll i = 0; i < crs.size(); ++i) {
      printf("%lld%c", crs[i], i == crs.size() - 1 ? '\n' : ' ');
    }
  }
}