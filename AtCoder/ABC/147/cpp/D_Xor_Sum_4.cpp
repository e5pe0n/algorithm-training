#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 300'000
#define MAX_M 60
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll res = 0;
  ll b = 1;
  for (ll j = 0; j < MAX_M; ++j) {
    ll cnt = 0;
    for (ll i = 0; i < N; ++i) {
      if (A[i] >> j & 1) ++cnt;
    }
    res = (res + b * cnt % MOD * (N - cnt) % MOD) % MOD;
    b = b * 2 % MOD;
  }
  printf("%lld\n", res);
}