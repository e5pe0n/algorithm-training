#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<bool> primes(ll n) {
  vector<bool> is_prime(n + 1, true);
  for (ll i = 2; i * i <= n; ++i) {
    if (is_prime[i]) {
      for (ll j = i + i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

ll _pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}

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

ll sigma_p(ll p, ll k) {
  return ((ll)_pow(p, k + 1) - 1) / (p - 1);
}

ll sigma(ll n) {
  map<ll, ll> ps = prime_factorize(n);
  ll res = 1;
  for (auto p : ps) {
    res *= sigma_p(p.first, p.second);
  }
  return res;
}

vector<pll> amicables(ll N) {
  vector<bool> is_prime = primes(N);
  vector<pll> res;
  ll cnt = 0;
  for (ll e = 2, b = 1; b <= N; ++e) {
    b = _pow(2, e - 1);
    ll p = 3 * b - 1;
    ll q = 2 * p + 1;
    ll r = (p + 1) * (q + 1) - 1;
    if (is_prime[p] && is_prime[q] && is_prime[r]) {
      ll m = 2 * b * p * q;
      ll n = 2 * b * r;
      res.push_back({m, n});
    }
  }
  return res;
}

void show(ll N) {
  vector<pll> res = amicables(N);
  for (auto p : res) {
    ll m = p.first, n = p.second;
    printf("m=%lld, n=%lld, sigma(%lld)=%lld, sigma(%lld)=%lld\n",
           m,
           n,
           m,
           sigma(m),
           n,
           sigma(n));
  }
}

int main() {
  show(100000);
  // m=220, n=284, sigma(220)=504, sigma(284)=504
  // m=17296, n=18416, sigma(17296)=35712, sigma(18416)=35712
  // m=9363584, n=9437056, sigma(9363584)=18800640, sigma(9437056)=18800640
}