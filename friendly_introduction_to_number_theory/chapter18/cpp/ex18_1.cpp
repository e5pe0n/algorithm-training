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
  } else {
    u = 1, v = 0;
  }
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
  // solve x^k = b (mod m) and return x
  ll ms = phi(m);
  ll u = mod_inv(k, ms);
  return mod_pow(b, u, m);
}

vector<ll> solve_bs(ll k, ll m, const vector<ll> &bs) {
  vector<ll> res;
  for (auto b : bs) {
    res.push_back(solve(k, b, m));
  }
  return res;
}

void show(ll k, ll m, const vector<ll> &bs) {
  vector<ll> res = solve_bs(k, m, bs);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  show(1789, 7081, {5129, 2604, 4222});
}