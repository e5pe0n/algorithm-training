#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N, M;

ll f(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; ++i) {
    res = res * i % MOD;
  }
  return res;
}

void solve() {
  if (N > M) {
    swap(N, M);
  }
  ll res = 0;
  if (M - N <= 1) {
    res = f(M) * f(N) % MOD;
    if (N == M) {
      res = res * 2 % MOD;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  solve();
}