#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_K 10
using namespace std;
typedef long long ll;

ll N, K;
set<ll> D;

ll dfs(ll n) {
  if (n >= N) return n;
  ll res = INF;
  if (n == 0) {
    for (ll i = 1; i < 10; ++i) {
      if (D.count(i) == 0) { res = min(res, dfs(i)); }
    }
  } else {
    for (ll i = 0; i < 10; ++i) {
      if (D.count(i) == 0) { res = min(res, dfs(n * 10 + i)); }
    }
  }
  return res;
}

void solve() {
  printf("%lld\n", dfs(0));
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < K; ++i) {
    ll d;
    cin >> d;
    D.insert(d);
  }
  solve();
}