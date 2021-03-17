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

ll mod_pow(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

void show(ll b, ll n, ll m) {
  printf("%lld^%lld(mod %lld)=%lld\n", b, n, m, mod_pow(b, n, m));
  map<ll, ll> ps = prime_factorize(m);
  printf("{");
  for (auto p : ps) {
    printf("%lld: %lld, ", p.first, p.second);
  }
  puts("}\n");
}

int main() {
  show(7, 7386, 7387);
  // 7^7386(mod 7387)=702
  // {83: 1, 89: 1, }

  show(7, 7392, 7393);
  // 7^7392(mod 7393)=1
  // {7393: 1, }
}