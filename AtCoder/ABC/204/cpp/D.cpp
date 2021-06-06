#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100;
const ll MAX_T = 1000;
const ll MAX_S = MAX_T * MAX_N;

ll N;
ll T[MAX_N];
ll dp[MAX_N + 1][MAX_S + 1];

int main() {
  cin >> N;
  ll S = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> T[i];
    S += T[i];
  }
  ll S2 = (S + 2 - 1) / 2;
  for (ll i = 0; i <= N; ++i)
    dp[i][0] = true;
  for (ll i = 1; i <= N; ++i) {
    for (ll j = 0; j < S; ++j) {
      if (dp[i - 1][j]) {
        dp[i][j] = true;
        if (j + T[i - 1] <= S) dp[i][j + T[i - 1]] = true;
      }
    }
  }
  for (ll j = S2; j <= S; ++j) {
    if (dp[N][j]) {
      cout << j << endl;
      return 0;
    }
  }
}