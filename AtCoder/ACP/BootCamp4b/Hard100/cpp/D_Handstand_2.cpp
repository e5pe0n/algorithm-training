#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

ll C[10][10]{};

ll dfs(ll n, ll N) {
  if (n > N) {
    return 0;
  }
  ll ret = n <= N;
  for (int i = 0; i < 10; ++i) {
    ret += dfs((n / 10 * 10 + i) * 10 + (n % 10), N);
  }
  return ret;
}

int main() {
  ll N;
  cin >> N;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      C[i][j] += i == j;
      C[i][j] += dfs(j * 10 + i, N);
    }
  }
  ll ans = 0;
  for (int i = 11; i <= N; ++i) {
    string i_str = to_string(i);
    ans += C[i_str[0] - '0'][i_str[i_str.size() - 1] - '0'];
  }
  for (int i = 1; i <= min(N, 9LL); ++i) {
    ans += C[i][i];
  }
  printf("%lld\n", ans);
}