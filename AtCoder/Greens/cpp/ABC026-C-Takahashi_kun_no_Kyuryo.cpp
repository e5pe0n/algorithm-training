#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 20
using namespace std;
typedef long long ll;

ll N;
vector<ll> G[MAX_N];

ll dfs(ll u) {
  if (G[u].size() == 0) return 1;
  ll mi = INF;
  ll ma = 0;
  for (auto v : G[u]) {
    ll x = dfs(v);
    mi = min(mi, x);
    ma = max(ma, x);
  }
  if (G[u].size() == 1) return mi * 2 + 1;
  return ma + mi + 1;
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    ll B;
    cin >> B;
    G[B - 1].push_back(i + 1);
  }
  printf("%lld\n", dfs(0));
}