#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

void show(ll b, ll n, ll m) {
  printf("%lld^%lld(mod %lld)=%lld\n", b, n, m, mod_pow(b, n, m));
}

int main() {
  show(2, 1000, 2379);       // 2^1000(mod 2379)=562
  show(567, 1234, 4321);     // 567^1234(mod 4321)=3214
  show(47, 258008, 1315171); // 47^258008(mod 1315171)=1296608
}