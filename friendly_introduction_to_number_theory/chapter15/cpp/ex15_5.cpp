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

ll sigma_p(ll p, ll k) {
  return ((ll)pow(p, k + 1) - 1) / (p - 1);
}

ll sigma(ll n) {
  map<ll, ll> ps = prime_factorize(n);
  ll res = 1;
  for (auto p : ps) {
    res *= sigma_p(p.first, p.second);
  }
  return res;
}

void show(ll n) {
  printf("sigma(%lld)=%lld\n", n, sigma(n));
}

int main() {
  for (ll i = 2; i <= 10; ++i) {
    show(i * i);
  }
}