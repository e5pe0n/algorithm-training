#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll n, a, b;

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll mod_comb(ll n, ll k) {
  ll x = n;
  for (ll i = n - 1; i > n - k; --i) {
    x = x * i % MOD;
  }
  ll y = k;
  for (ll i = k - 1; i > 0; --i) {
    y = y * i % MOD;
  }
  return x * mod_pow(y, MOD - 2) % MOD;
}

void solve() {
  ll all = mod_pow(2, n) - 1;
  ll case_a = mod_comb(n, a);
  ll case_b = mod_comb(n, b);
  ll res = (all - case_a - case_b + 2 * MOD) % MOD;
  printf("%lld\n", res);
}

int main() {
  cin >> n >> a >> b;
  solve();
}