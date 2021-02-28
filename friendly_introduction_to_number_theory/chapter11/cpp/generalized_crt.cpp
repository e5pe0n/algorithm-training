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

ll pos(ll x, ll m) {
  x %= m;
  return (x + m) % m;
}

ll crt2(ll b, ll m, ll c, ll n) {
  // solve the two simultaneous congruences: x = b (mod m), x = c (mod n)
  ll x, y, z;
  ll g = __gcd(m, n);
  extgcd(m, n, y, z);
  ll _c = (c - b + n) % n;
  if (_c % g != 0) return -1;
  x = m * _c * y + b;
  return pos(x, m / g * n);
}

ll crt(vector<ll> C, vector<ll> M) {
  // solve the n simultaneous congruences:
  // x = C0 (mod M0), x = C1 (mod M1), ..., x = Cn (mod Mn)
  assert(C.size() == M.size());
  ll lcm = 1;
  ll x = 0;
  for (ll i = 0; i < C.size(); ++i) {
    x = crt2(x, lcm, C[i], M[i]);
    if (x == -1) return -1;
    lcm = lcm * __gcd(lcm, M[i]) * M[i];
    x = pos(x, lcm);
  }
  return x;
}

void show(ll x, vector<ll> M) {
  printf("x = %lld\n", x);
  for (auto m : M)
    printf("x mod %lld = %lld\n", m, x % m);
  puts("");
}

int main() {
  vector<ll> C1{3, 5}, M1{7, 9};
  show(crt(C1, M1), M1);

  vector<ll> C2{3, 1}, M2{37, 87};
  show(crt(C2, M2), M2);

  vector<ll> C3{3, 10}, M3{8, 12};
  show(crt(C3, M3), M3);

  vector<ll> C4{5, 2, 8}, M4{7, 12, 13};
  show(crt(C4, M4), M4);

  vector<ll> C5{2, 3, 1}, M5{3, 4, 5};
  show(crt(C5, M5), M5);

  vector<ll> C6{2, 10}, M6{8, 12};
  show(crt(C6, M6), M6);

  // x = 3 (mod 7), x = 5 (mod 9)
  // ll x = crt2(3, 7, 5, 9);
  // printf("x = %lld\n", x);
  // printf("x mod 7 = %lld\n", x % 7);
  // printf("x mod 9 = %lld\n", x % 9);
  // puts("");

  // // x = 3 (mod 37), x = 1 (mod 87)
  // x = crt2(3, 37, 1, 87);
  // printf("x = %lld\n", x);
  // printf("x mod 37 = %lld\n", x % 37);
  // printf("x mod 87 = %lld\n", x % 87);
  // puts("");

  // // x = 3 (mod 8), x = 10 (mod 12)
  // x = crt2(3, 8, 10, 12);
  // printf("x = %lld\n", x);
}