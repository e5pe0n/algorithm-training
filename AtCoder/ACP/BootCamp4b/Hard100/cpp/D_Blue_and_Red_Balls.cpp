#include <iostream>
#include <stdio.h>

#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

ll N, K;

ll mod_pow(ll x, ll n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) {
      ret = ret * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}

ll mod_comb(ll n, ll k) {
  if (k <= 0) {
    return 1;
  }
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

int main() {
  cin >> N >> K;
  for (int i = 1; i <= K; ++i) {
    ll ans = mod_comb(N - K + 1, i) * mod_comb(K - 1, i - 1) % MOD;
    printf("%lld\n", ans);
  }
}