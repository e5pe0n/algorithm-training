#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_N];

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll cnt = 0;
  ll a0 = A[0];
  while (a0 % 2 == 0) {
    a0 /= 2;
    ++cnt;
  }
  ll lcm = A[0];
  ll f = true;
  for (ll i = 0; i < N; ++i) {
    ll t = 0;
    while (A[i] % 2 == 0) {
      A[i] /= 2;
      ++t;
    }
    if (cnt != t) f = false;
    lcm = lcm / __gcd(lcm, A[i]) * A[i];
  }
  ll res = 0;
  if (f) res = (M / (lcm / 2) + 2 - 1) / 2;
  printf("%lld\n", res);
}