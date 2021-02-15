#include <bits/stdc++.h>
#define MAX_N 3000
using namespace std;
typedef long long ll;

ll N;
ll R[MAX_N];
ll dp[MAX_N][2];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> R[i];
  }
  for (ll i = 0; i < N; ++i) {
    dp[i][0] = dp[i][1] = 1;
    for (ll j = 0; j < i; ++j) {
      if (R[j] < R[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
      if (R[j] > R[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
    }
  }
  ll res = max(dp[N - 1][0], dp[N - 1][1]);
  if (res < 3) res = 0;
  printf("%lld\n", res);
}