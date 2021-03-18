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

ll _pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
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

ll extgcd(ll a, ll b, ll &u, ll &v) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, v, u);
    v -= (a / b) * u;
  } else
    u = 1, v = 0;
  return d;
}

ll pos(ll x, ll m) {
  x %= m;
  return (x + m) % m;
}

ll mod_inv(ll x, ll m) {
  ll u, v;
  extgcd(x, m, u, v);
  return pos(u, m);
}

ll phi(ll n) {
  map<ll, ll> ps = prime_factorize(n);
  ll res = n;
  for (auto p : ps) {
    res = res / p.first * (p.first - 1);
  }
  return res;
}

ll solve(ll k, ll b, ll m) {
  ll ms = phi(m);
  ll u = mod_inv(k, ms);
  return mod_pow(b, u, m);
}

void show(ll k, ll b, ll m) {
  ll res = solve(k, b, m);
  ll check = mod_pow(res, k, m);
  printf("x^%lld=%lld(mod %lld) -> x=%lld, check=%lld\n", k, b, m, res, check);
}

int main() {
  show(131, 758, 1073);
  show(329, 452, 1147);
  show(113, 347, 463);
  show(275, 139, 588);
}