#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];

ll P[MAX_N + 1], Q[MAX_N + 1];

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
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
  for (ll i = N; i > 0; --i) {
    Q[i - 1] = Q[i] * i % MOD;
  }
}

ll mod_com(ll n, ll k) {
  if (n < 0 || k < 0 || n < k) return 0;
  if (k == 0) return 1;
  return P[n] * Q[n - k] % MOD * Q[k] % MOD;
}

void solve() {
  init();
  sort(A, A + N);
  ll res = 0;
  for (ll i = K - 1; i < N; ++i) {
    res = (res + mod_com(i, K - 1) * A[i] % MOD) % MOD;
  }
  for (ll i = 0; i < N - K + 1; ++i) {
    res = (res - mod_com(N - i - 1, K - 1) * A[i] % MOD + MOD) % MOD;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}