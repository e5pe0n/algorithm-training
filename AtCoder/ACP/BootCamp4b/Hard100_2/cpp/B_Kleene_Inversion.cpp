#include <bits/stdc++.h>
#define MAX_N 2000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];
ll C[MAX_N];

void solve() {
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (A[i] > A[j]) {
        res = (res + K * (K + 1) / 2) % MOD;
      } else if (A[i] < A[j]) {
        res = (res + (K - 1) * K / 2) % MOD;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}