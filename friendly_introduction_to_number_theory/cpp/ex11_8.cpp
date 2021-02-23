#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

ll f(ll b, ll m, ll c, ll n) {
  // solve the simultaneous congruence: x = b (mod m), x = c (mod n)
  // and return x.
  // (m and n must be primitive each other i.e. must be gcd(m, n) = 1)
  ll x, y, z;
  extgcd(m, n, y, z);
  ll _c = (c - b + n) % n;
  x = (m * _c * y + b) % (m * n);
  x = (x + m * n) % (m * n);
  return x;
}

int main() {
  // x = 3 (mod 7), x = 5 (mod 9)
  ll x = f(3, 7, 5, 9);
  printf("x = %lld\n", x);
  printf("x mod 7 = %lld\n", x % 7);
  printf("x mod 9 = %lld\n", x % 9);
  puts("");

  // x = 3 (mod 37), x = 1 (mod 87)
  x = f(3, 37, 1, 87);
  printf("x = %lld\n", x);
  printf("x mod 37 = %lld\n", x % 37);
  printf("x mod 87 = %lld\n", x % 87);
}