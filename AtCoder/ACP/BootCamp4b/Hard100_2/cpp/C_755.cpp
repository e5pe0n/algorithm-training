#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll C[10];

ll dfs(ll n) {
  if (n > N) return 0;
  fill(C, C + 10, 0);
  ll _n = n;
  while (_n > 0) {
    ++C[_n % 10];
    _n /= 10;
  }
  bool f = true;
  for (ll i = 3; i <= 7; i += 2) {
    if (C[i] == 0) f = false;
  }
  ll res = f;
  for (ll i = 3; i <= 7; i += 2) {
    res += dfs(n * 10 + i);
  }
  return res;
}

void solve() {
  ll res = dfs(0);
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}