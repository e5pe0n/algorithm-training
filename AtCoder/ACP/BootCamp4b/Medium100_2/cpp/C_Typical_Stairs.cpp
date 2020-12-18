#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_M];
bool B[MAX_N + 1];
ll dp[MAX_N + 1];

void solve() {
  for (int i = 0; i < M; ++i) {
    B[A[i]] = true;
  }
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    if (i + 1 <= N && !B[i + 1]) {
      dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    }
    if (i + 2 <= N && !B[i + 2]) {
      dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
    }
  }
  printf("%lld\n", dp[N]);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> A[i];
  }
  solve();
}