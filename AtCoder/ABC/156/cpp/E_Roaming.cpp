#include <bits/stdc++.h>
#define MAX_N 200'000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N, K;
ll p[MAX_N + 1], q[MAX_N + 1];

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
  p[0] = 1;
  for (ll i = 1; i <= N; ++i) {
    p[i] = p[i - 1] * i % MOD;
  }
  q[N] = inv(p[N]);
  for (ll i = N; i >= 1; --i) {
    q[i - 1] = q[i] * i % MOD;
  }
}

ll comb(ll n, ll k) {
  if (k == 0) { return 1; }
  if (k < 0 || k > n) { return 0; }
  return p[n] * q[n - k] % MOD * q[k] % MOD;
}

void solve() {
  init();
  printf("4C2=%lld\n", comb(4, 2));
  ll res = 0;
  for (int i = 0; i <= min(K, N - 1); ++i) {
    res = (res + comb(N, i) * comb(N - 1, N - i - 1) % MOD) % MOD;
    if (res < 0) {
      printf("i=%d, res=%lld\n", i, res);
      printf("comb(%lld, %d)=%lld, comb(%lld, %lld)=%lld\n",
             N,
             i,
             comb(N, i),
             N - 1,
             N - i - 1,
             comb(N - 1, N - i - 1));
      break;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  solve();
}