#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
const ll MAX_M = 200'000;
ll N, M;
vector<ll> G[MAX_N];
vector<ll> H[MAX_N];
vector<ll> V;
bool used[MAX_N];
ll cnt = 0;

void dfs(ll u) {
  used[u] = true;
  for (auto v : G[u])
    if (!used[v]) dfs(v);
  V.push_back(u);
}

void dfs2(ll u) {
  used[u] = true;
  ++cnt;
  for (auto v : H[u])
    if (!used[v]) dfs2(v);
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    H[b].push_back(a);
  }

  for (ll u = 0; u < N; ++u) {
    if (!used[u]) { dfs(u); }
  }

  ll res = 0;
  reverse(V.begin(), V.end());
  fill(used, used + N, false);
  for (auto u : V) {
    if (used[u]) continue;
    cnt = 0;
    dfs2(u);
    res += cnt * (cnt - 1) / 2;
  }
  printf("%lld\n", res);
}