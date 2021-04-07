#include <bits/stdc++.h>
#define MAX_N 200'000
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N;
ll C[MAX_N + 1];
ll dp[MAX_N + 1];
ll sum[MAX_N + 1];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> C[i];
  }
  vector<ll> V{C[0]};
  for (ll i = 1; i < N; ++i) {
    if (V[V.size() - 1] != C[i]) V.push_back(C[i]);
  }
  N = V.size();
  fill(dp, dp + N + 1, 0);
  dp[0] = 1;
  for (ll i = 1; i <= N; ++i) {
    dp[i] = (dp[i - 1] + sum[V[i - 1]]) % MOD;
    sum[V[i - 1]] = dp[i];
  }
  printf("%lld\n", dp[N]);
}