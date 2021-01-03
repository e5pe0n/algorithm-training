#include <bits/stdc++.h>
#define MAX_N 100'000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  map<ll, ll> C;
  for (int i = 0; i < N; ++i) {
    ++C[A[i]];
  }
  ll res = 1;
  if (N % 2 == 0) {
    for (int i = 1; i <= N - 1; i += 2) {
      if (C[i] != 2) {
        res = 0;
        break;
      }
      res = res * 2 % MOD;
    }
  } else {
    if (C[0] != 1) {
      res = 0;
    } else {
      for (int i = 2; i <= N - 1; i += 2) {
        if (C[i] != 2) {
          res = 0;
          break;
        }
        res = res * 2 % MOD;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}