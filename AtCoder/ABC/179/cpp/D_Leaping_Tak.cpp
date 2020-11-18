#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000
#define MAX_K 10
#define MOD 998244353

using namespace std;
typedef long long ll;

int N, K;
int L[MAX_K], R[MAX_K];
ll dp[MAX_N], sdp[MAX_N + 1];

int main() {
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> L[i] >> R[i];
  }
  dp[0] = 1;
  sdp[1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      int left = max(0, i - R[j]);
      int right = max(0, i - L[j] + 1);
      dp[i] = (dp[i] + sdp[right] - sdp[left] + MOD) % MOD;
    }
    sdp[i + 1] = (sdp[i] + dp[i]) % MOD;
  }
  printf("%lld\n", dp[N - 1]);
}