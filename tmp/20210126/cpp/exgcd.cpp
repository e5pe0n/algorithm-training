#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    printf("a=%lld, b=%lld, x=%lld, y=%lld\n", a, b, x, y);
  } else {
    x = 1, y = 2;
  }
  return d;
}

int main() {
  ll x, y;
  printf("%lld\n", extgcd(30, 11, x, y));
  printf("x=%lld, y=%lld\n", x, y);
}