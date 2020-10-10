#include <iostream>
#include <stdio.h>

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
  int X, Y;
  cin >> X >> Y;
  int z = X + Y;
  if (z % 3 != 0) {
    printf("0\n");
    return 0;
  }
  int n = z / 3;
  int k = -1;
  for (int i = n; i <= z - n; ++i) {
    if (X == i || Y == i) {
      k = z - n - i;
      break;
    }
  }
  if (k == -1) {
    printf("0\n");
    return 0;
  }
  ll a = n;
  for (ll i = n - 1; i > n - k; --i) {
    a = (a * i) % MOD;
  }
  ll b = k;
  for (ll i = k - 1; i > 0; --i) {
    b = (b * i) % MOD;
  }
  ll res = a * mod_pow(b, MOD - 2) % MOD;
  printf("%lld\n", res);
}