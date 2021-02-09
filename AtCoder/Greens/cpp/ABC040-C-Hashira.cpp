#include <bits/stdc++.h>
#define INF 1'000'000'000'000'000'000
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll dp[MAX_N + 1];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  fill(dp, dp + N, INF);
  dp[0] = 0;
  for (ll i = 1; i < N; ++i) {
    if (i - 2 >= 0) { dp[i] = min(dp[i], dp[i - 2] + abs(A[i - 2] - A[i])); }
    dp[i] = min(dp[i], dp[i - 1] + abs(A[i - 1] - A[i]));
  }
  printf("%lld\n", dp[N - 1]);
}