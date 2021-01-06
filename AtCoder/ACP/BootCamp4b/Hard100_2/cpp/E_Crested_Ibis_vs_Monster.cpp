#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_H 10'000
#define MAX_N 1'000
using namespace std;
typedef long long ll;

ll H, N;
ll A[MAX_N], B[MAX_N];
ll dp[MAX_H + 1];

void solve() {
  fill(dp, dp + MAX_H + 1, INF);
  dp[0] = 0;
  for (ll i = 0; i <= H; ++i) {
    for (ll j = 0; j < N; ++j) {
      ll a = A[j];
      ll b = B[j];
      ll nxt = min(H, i + a);
      dp[nxt] = min(dp[nxt], dp[i] + b);
    }
  }
  printf("%lld\n", dp[H]);
}

int main() {
  cin >> H >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}