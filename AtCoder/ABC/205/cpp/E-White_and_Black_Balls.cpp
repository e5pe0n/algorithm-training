#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll mod_inv(ll x) {
  return mod_pow(x, MOD - 2);
}

ll mod_com(ll n, ll k) {
  if (k < 0 || n < 0 || n < k) return 0;
  if (k == 0) return 1;
  ll x = 1;
  for (ll i = n; i > n - k; --i) {
    x = x * i % MOD;
  }
  ll y = 1;
  for (ll i = 1; i <= k; ++i) {
    y = y * i % MOD;
  }
  return x * mod_inv(y) % MOD;
}

ll N, M, K;

int main() {
  cin >> N >> M >> K;
  ll res = 0;
  if (N <= M + K) {
    res = ((mod_com(N + M, N) - mod_com(N + M, M + K + 1)) % MOD + MOD) % MOD;
  }
  printf("%lld\n", res);
}