#include <iostream>
#include <stdio.h>

#define MOD 1'000'000'007
#define MAX_N 200'000

using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll sum[MAX_N + 1];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    sum[i + 1] = (sum[i] + A[i]) % MOD;
  }
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    res = (res + A[i] * ((sum[N] - sum[i + 1] + MOD) % MOD)) % MOD;
  }
  printf("%lld\n", res);
}