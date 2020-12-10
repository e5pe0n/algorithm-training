#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

string S;
ll N, K;
ll dp[MAX_N + 1][2][4];

void solve() {
  N = S.size();
  fill((ll *)dp, (ll *)dp + sizeof(dp) / sizeof(ll), 0);
  dp[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    int D = S[i] - '0';
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k <= K; ++k) {
        if (k == K) {
          dp[i + 1][j][k] += dp[i][j][k];
          continue;
        }
        for (int d = 0; d <= (j ? 9 : D); ++d) {
          if (d == 0) {
            dp[i + 1][j || (d < D)][k] += dp[i][j][k];
          } else {
            dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
          }
        }
      }
    }
  }
  printf("%lld\n", dp[N][0][K] + dp[N][1][K]);
}

int main() {
  cin >> S >> K;
  solve();
}