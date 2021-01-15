#include <bits/stdc++.h>
#define MAX_N 100'000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll C[MAX_N];

void solve() {
  ll n = 3;
  ll res = 1;
  for (ll i = 0; i < N; ++i) {
    if (A[i] == 0) {
      res = res * n % MOD;
      --n;
    } else {
      res = res * C[A[i] - 1] % MOD;
      --C[A[i] - 1];
    }
    ++C[A[i]];
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