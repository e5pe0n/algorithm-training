#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll K;
ll cnt;

ll dfs(string n, ll k) {
  ll res = 0;
  if (n.size() >= k) {
    ++cnt;
    if (cnt == K) {
      res = stoll(n);
    } else {
      res = 0LL;
    }
    return res;
  }
  if (n.size() == 0) {
    for (int i = 1; i <= 9; ++i) {
      res += dfs(to_string(i), k);
    }
    return res;
  }
  int last = n[n.size() - 1] - '0';
  for (int i = max(0, last - 1); i <= min(9, last + 1); ++i) {
    res += dfs(n + to_string(i), k);
  }
  return res;
}

void solve() {
  for (int k = 1; k < INF; ++k) {
    if (ll res = dfs("", k)) {
      printf("%lld\n", res);
      return;
    }
  }
}

int main() {
  cin >> K;
  solve();
}