#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;

vector<pll> divisors(ll n) {
  vector<pll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
        res.push_back({i, n / i});
    }
  }
  return res;
}

void solve() {
  vector<pll> V = divisors(N);
  ll res = 10;
  for (auto p : V) {
    res = min(res, (ll)max(to_string(p.first).size(), to_string(p.second).size()));
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}