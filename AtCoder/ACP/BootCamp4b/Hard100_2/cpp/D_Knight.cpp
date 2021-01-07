#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll X, Y;

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) { res = res * x % MOD; }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll inv(ll x) {
  return mod_pow(x, MOD - 2);
}

ll mod_com(ll n, ll k) {
  ll x = 1;
  for (ll i = n; i > n - k; --i) {
    x = x * i % MOD;
  }
  ll y = 1;
  for (ll i = k; i > 0; --i) {
    y = y * i % MOD;
  }
  return x * inv(y) % MOD;
}

void solve() {
  ll res = 0;
  if ((X + Y) % 3 == 0 && abs(X - Y) <= (X + Y) / 3) { res = mod_com((X + Y) / 3, abs((X + Y) / 3 - X)); }
  printf("%lld\n", res);
}

int main() {
  cin >> X >> Y;
  solve();
}