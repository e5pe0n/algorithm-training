#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

ll mod_pow(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

int main() {
  cin >> N >> M;
  ll res = mod_pow(10, N, M * M) / M % M;
  printf("%lld\n", res);
}