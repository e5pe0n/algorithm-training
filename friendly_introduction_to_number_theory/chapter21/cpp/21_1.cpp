#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &u, ll &v) {
  // solves a * u + b * v = gcd(a, b)
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
  // returns the inverse of x modulo m
  // by solving x * mod_inv(x) + m * v = gcd(x, m)
  ll u, v;
  extgcd(x, m, u, v);
  return pos(u, m);
}

ll solve(ll a, ll c, ll m) {
  // returns x satisfying a * x equiv c (mod m).
  return c * mod_inv(a, m) % m;
}

int main() {
  printf("%lld\n", solve(14, 33, 337)); // 14x equiv 33 (mod 337) -> x = 219
  printf("%lld\n",
         solve(64, 941, 3011)); // 64x equiv 941 (mod 3011) -> x = 2320
}