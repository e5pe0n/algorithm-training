#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 300'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  ll t = 0;
  ll res = 0;
  ll b = 1;
  for (ll j = 0; j < 60; ++j) {
    ll one = 0;
    for (ll i = 0; i < N; ++i) {
      if (A[i] >> j & 1) { ++one; }
    }
    ll _one = one * (N - one) % MOD;
    res = (res + b * _one % MOD) % MOD;
    b = b * 2 % MOD;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}