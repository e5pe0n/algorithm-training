#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 2000
using namespace std;
typedef long long ll;

ll N;
ll P[MAX_N + 1], Q[MAX_N + 1];

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) { res = res * x % MOD; }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll inv(ll x) {
  return mod_pow(x, MOD - 2);
}

void init() {
  P[0] = 1;
  for (ll i = 1; i <= N; ++i) {
    P[i] = P[i - 1] * i % MOD;
  }
  Q[N] = inv(P[N]);
  for (ll i = N; i >= 1; --i) {
    Q[i - 1] = Q[i] * i % MOD;
  }
}

ll mod_com(ll n, ll k) {
  if (k == 0) { return 1; }
  if (k < 0 || k > n) { return 0; }
  return ((P[n] * Q[n - k]) % MOD * Q[k]) % MOD;
}

void solve() {
  init();
  printf("6C2=%lld\n", mod_com(6, 2)); // 15
  printf("6C0=%lld\n", mod_com(6, 0)); // 1
  printf("6C8=%lld\n", mod_com(6, 8)); // 0
}

int main() {
  cin >> N;
  solve();
}