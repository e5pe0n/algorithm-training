#include <iostream>
#include <stdio.h>

#define MAX_N 2000
#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

int A[MAX_N];

int main() {
  ll N, K;
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll res = 0;
  for (ll i = 0; i < N - 1; ++i) {
    ll _cnt = 0;
    ll cnt = 0;
    for (ll j = i + 1; j < N; ++j) {
      if (A[i] < A[j]) {
        ++cnt;
      } else if (A[i] > A[j]) {
        ++_cnt;
      }
    }
    res += (cnt * (((K - 1) * K / 2) % MOD) + _cnt * ((K * (K + 1) / 2) % MOD)) % MOD;
  }
  printf("%lld\n", res % MOD);
}