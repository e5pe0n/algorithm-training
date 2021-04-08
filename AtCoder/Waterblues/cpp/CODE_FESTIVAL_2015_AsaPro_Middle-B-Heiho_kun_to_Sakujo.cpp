#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
string S;

ll dp[MAX_N + 1][MAX_N + 1];

ll lcs(string s, string t) {
  for (ll i = 0; i <= N; ++i) {
    fill(dp[i], dp[i] + N + 1, 0);
  }
  for (ll i = 0; i < s.size(); ++i) {
    for (ll j = 0; j < t.size(); ++j) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  return dp[s.size()][t.size()];
}

int main() {
  cin >> N >> S;
  ll res = N;
  for (ll i = 1; i < N; ++i) {
    res = min(res, N - 2 * lcs(S.substr(0, i), S.substr(i)));
  }
  printf("%lld\n", res);
}