#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

ll N, M, K;

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

int main() {
  cin >> N >> M >> K;
  ll res = M * mod_pow(M - 1, N - 1) % MOD;
  ll x = 1;
  ll y = 1;
  for (int k = 1; k <= K; ++k) {
    x = x * (N - k) % MOD;
    y = y * k % MOD;
    res = (res + M * x % MOD * mod_pow(y, MOD - 2) % MOD * mod_pow(M - 1, N - 1 - k) % MOD) % MOD;
  }
  printf("%lld\n", res);
}