#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) { res *= x; }
    x *= x;
    n >>= 1;
  }
  return res;
}

int main() {
  printf("%lld\n", _pow(3, 10));
}