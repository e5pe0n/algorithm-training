#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;
ll cnt;

ll dfs(string s, ll n) {
  if (s.size() >= n) {
    ++cnt;
    if (cnt == K) {
      return stoll(s);
    } else {
      return 0;
    }
  }
  ll res = 0;
  if (s == "") {
    for (ll i = 1; i <= 9; ++i) {
      res += dfs(to_string(i), n);
    }
  } else {
    ll last = s[s.size() - 1] - '0';
    for (ll i = max(0LL, last - 1); i <= min(9LL, last + 1); ++i) {
      res += dfs(s + to_string(i), n);
    }
  }
  return res;
}

void solve() {
  ll res = 0;
  for (ll i = 1; i < 1'000'000; ++i) {
    if ((res = dfs("", i)) > 0) {
      printf("%lld\n", res);
      return;
    }
  }
}

int main() {
  cin >> K;
  solve();
}