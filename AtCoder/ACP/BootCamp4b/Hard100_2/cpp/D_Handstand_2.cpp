#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

ll dfs(ll n) {
  if (n > N) return 0;
  ll res = n <= N;
  for (ll i = 0; i < 10; ++i) {
    res += dfs((n / 10 * 10 + i) * 10 + (n % 10));
  }
  return res;
}

void solve() {
  ll res = 0;
  for (ll i = 1; i < 10; ++i) {
    for (ll j = i; j < 10; ++j) {
      if (i == j) {
        ll t = (i <= N) + dfs(i * 10 + i);
        res += t * t;
      } else {
        ll left = dfs(i * 10 + j);
        ll right = dfs(j * 10 + i);
        res += left * right * 2;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}