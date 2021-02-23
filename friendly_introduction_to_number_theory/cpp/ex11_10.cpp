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

ll phi(ll n) {
  map<ll, ll> factors = prime_factorize(n);
  ll res = n;
  for (auto p : factors)
    res = res / p.first * (p.first - 1);
  return res;
}

int main() {
  for (ll i = 1; i <= 100; ++i) {
    printf("i=%lld, phi=%lld\n", i, phi(i));
  }
}