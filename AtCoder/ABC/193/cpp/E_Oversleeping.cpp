// WA
#include <bits/stdc++.h>
#define INF 4'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

ll pos(ll x, ll m) {
  x %= m;
  return (x + m) % m;
}

ll crt2(ll b, ll m, ll c, ll n) {
  // solve the two simultaneous congruences: x = b (mod m), x = c (mod n)
  ll x, y, z;
  ll g = __gcd(m, n);
  extgcd(m, n, y, z);
  ll _c = (c - b + n) % n;
  if (_c % g != 0) return -1;
  x = m * _c * y + b;
  return pos(x, m / g * n);
}

ll crt(vector<ll> C, vector<ll> M) {
  // solve the n simultaneous congruences:
  // x = C0 (mod M0), x = C1 (mod M1), ..., x = Cn (mod Mn)
  assert(C.size() == M.size());
  ll lcm = 1;
  ll x = 0;
  for (ll i = 0; i < C.size(); ++i) {
    x = crt2(x, lcm, C[i], M[i]);
    if (x == -1) return -1;
    lcm = lcm * __gcd(lcm, M[i]) * M[i];
  }
  return x;
}

ll T, X, Y, P, Q;

int main() {
  cin >> T;
  while (T--) {
    cin >> X >> Y >> P >> Q;
    ll res = INF;
    for (ll t1 = X; t1 < X + Y; ++t1) {
      for (ll t2 = P; t2 < P + Q; ++t2) {
        ll t = crt({t1, t2}, {(X + Y) * 2, P + Q});
        if (t == -1) continue;
        if (res > t) res = t;
      }
    }
    if (res == INF)
      puts("infinity");
    else
      printf("%lld\n", res);
  }
}