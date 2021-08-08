#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 200'000;
ll N;
vector<ll> G[MAX_N];
bool used[MAX_N];
vector<ll> res;

void dfs(ll u) {
  res.push_back(u);
  for (auto v : G[u]) {
    if (!used[v]) {
      used[v] = true;
      dfs(v);
      res.push_back(u);
    }
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (ll i = 0; i < N; ++i) {
    sort(G[i].begin(), G[i].end());
  }
  used[0] = true;
  dfs(0);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i] + 1, i == res.size() - 1 ? '\n' : ' ');
  }
}