#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

ll dfs(string n_str, ll N) {
  if (n_str.size() > 0 && stoll(n_str) > N) {
    return 0;
  }
  string s = "357";
  int cnt = 0;
  for (auto c : s) {
    for (auto _c : n_str) {
      if (c == _c) {
        ++cnt;
        break;
      }
    }
  }
  ll ret = cnt == 3;
  for (auto c : s) {
    ret += dfs(n_str + c, N);
  }
  return ret;
}

int main() {
  ll N;
  cin >> N;
  ll ans = dfs("", N);
  printf("%lld\n", ans);
}