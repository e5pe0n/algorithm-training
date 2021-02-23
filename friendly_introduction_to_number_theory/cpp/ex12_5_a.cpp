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

ll f(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

int main() {
  for (ll i = 2; i <= 20; ++i) {
    ll fact = f(i);
    map<ll, ll> ps = prime_factorize(fact);
    printf("i=%lld, fact=%lld, 2^%lld, 3^%lld\n", i, fact, ps[2], ps[3]);
  }
}