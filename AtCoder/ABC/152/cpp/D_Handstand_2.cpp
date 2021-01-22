#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

ll dfs(ll n) {
  if (n > N) return 0;
  ll res = 1;
  for (ll i = 0; i < 10; ++i) {
    res += dfs((n / 10 * 100) + 10 * i + n % 10);
  }
  return res;
}

void solve() {
  ll res = 0;
  for (ll i = 1; i < 10; ++i) {
    for (ll j = i; j < 10; ++j) {
      if (i == j && i <= N) {
        ll cnt = dfs(i * 10 + j) + 1;
        res += cnt * cnt;
      } else {
        ll cnt1 = dfs(i * 10 + j);
        ll cnt2 = dfs(j * 10 + i);
        res += cnt1 * cnt2 * 2;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}