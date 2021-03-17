#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

bool _is_prime(ll n) {
  default_random_engine generator;
  uniform_int_distribution<ll> distribution(2, n - 1);
  for (ll i = 0; i < 10; ++i) {
    ll a = distribution(generator);
    if (mod_pow(a, n - 1, n) != 1) return false;
  }
  return true;
}

void is_prime(ll n) {
  if (_is_prime(n))
    printf("%lld is probably prime.\n", n);
  else
    printf("%lld is composite.\n", n);
}

int main() {
  // primes
  for (auto v : vector<ll>{1103, 1723, 2467, 2819, 6607, 8923})
    is_prime(v);
  // 1103 is probably prime.
  // 1723 is probably prime.
  // 2467 is probably prime.
  // 2819 is probably prime.
  // 6607 is probably prime.
  // 8923 is probably prime.

  // carmicaels
  for (auto v : vector<ll>{1105, 1729, 2465, 2821, 6601, 8911})
    is_prime(v);
  // 1105 is composite.
  // 1729 is composite.
  // 2465 is composite.
  // 2821 is composite.
  // 6601 is probably prime.
  // 8911 is composite.
}