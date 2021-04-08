#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

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

pll calc_k_q(ll n) {
  ll k = 0;
  ll q = n - 1;
  while (q % 2 == 0) {
    ++k;
    q >>= 1;
  }
  return {k, q};
}
ll mod_pow(__int128_t x, __int128_t n, __int128_t m) {
  __int128_t res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

int main() {
  ll n = 100000000069;
  map<ll, ll> ps = prime_factorize(n);
  for (auto p : ps) {
    printf("%lld: %lld\n", p.first, p.second);
  }
  map<ll, ll> ps2 = prime_factorize(n - 1);
  for (auto p : ps2) {
    printf("%lld: %lld\n", p.first, p.second);
  }
  auto [k, q] = calc_k_q(n);
  printf("k=%lld, q=%lld\n", k, q);
  ll a_q = mod_pow(3, q, n);
  printf("a_q=%lld\n", a_q);
  for (ll i = 0; i < k; ++i) {
    a_q = mod_pow(a_q, 2, n);
    printf("a_q=%lld\n", a_q);
  }
}