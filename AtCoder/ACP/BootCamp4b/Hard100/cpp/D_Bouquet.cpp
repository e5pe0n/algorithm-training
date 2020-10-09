#include <iostream>
#include <stdio.h>

#define MAX_N 1'000'000'000
#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

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

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n == 2) {
    printf("0\n");
    return 0;
  }
  ll ans = mod_pow(2, n) - 1;
  ll xa = n;
  for (ll i = n - 1; i > n - a; --i) {
    xa = xa * i % MOD;
  }
  ll ya = a;
  for (ll i = a - 1; i > 0; --i) {
    ya = ya * i % MOD;
  }
  ll xb = n;
  for (ll i = n - 1; i > n - b; --i) {
    xb = xb * i % MOD;
  }
  ll yb = b;
  for (ll i = b - 1; i > 0; --i) {
    yb = yb * i % MOD;
  }
  ll ca = xa * mod_pow(ya, MOD - 2) % MOD;
  ll cb = xb * mod_pow(yb, MOD - 2) % MOD;
  ans = (ans + MOD * 2 - ca - cb) % MOD;
  printf("%lld\n", ans);
}