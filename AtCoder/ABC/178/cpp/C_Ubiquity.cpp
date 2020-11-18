#include <iostream>
#include <stdio.h>

#define MOD 1'000'000'007

using namespace std;

typedef long long ll;

ll N;

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
  cin >> N;
  ll res = mod_pow(10, N) - 2 * mod_pow(9, N) + mod_pow(8, N);
  res %= MOD;
  res = (res + MOD) % MOD;
  printf("%lld\n", res);
}