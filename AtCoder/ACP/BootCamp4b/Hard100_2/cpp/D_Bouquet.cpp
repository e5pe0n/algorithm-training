#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N, A, B;

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
  ll res = mod_pow(2, N) - 1;
  ll ca = mod_com(N, A);
  ll cb = mod_com(N, B);
  res = (res + MOD * 2 - ca - cb) % MOD;
  printf("%lld\n", res);
}

int main() {
  cin >> N >> A >> B;
  solve();
}