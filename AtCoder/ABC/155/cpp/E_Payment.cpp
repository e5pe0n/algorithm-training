#include <bits/stdc++.h>
#define MAX_N 1'000'000
using namespace std;

string N;
int dp[2][MAX_N + 1];

void solve() {
  int *ext = dp[0];
  int *jst = dp[1];
  ext[0] = 1;
  for (int i = 1; i <= N.size(); ++i) {
    int n = N[i - 1] - '0';
    ext[i] = min(ext[i - 1] + 10 - (n + 1), jst[i - 1] + (n + 1));
    jst[i] = min(ext[i - 1] + 10 - n, jst[i - 1] + n);
  }
  printf("%d\n", jst[N.size()]);
}

int main() {
  cin >> N;
  solve();
}