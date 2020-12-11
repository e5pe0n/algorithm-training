#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_H 10000
#define MAX_N 1000
using namespace std;
typedef long long ll;

ll H, N;
ll A[MAX_N], B[MAX_N];
ll dp[MAX_H + 1];

void solve() {
  fill((ll *)dp, (ll *)dp + sizeof(dp) / sizeof(ll), INF);
  dp[0] = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      ll nxt = min(i + A[j], H);
      dp[nxt] = min(dp[nxt], dp[i] + B[j]);
    }
  }
  printf("%lld\n", dp[H]);
}

int main() {
  cin >> H >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}