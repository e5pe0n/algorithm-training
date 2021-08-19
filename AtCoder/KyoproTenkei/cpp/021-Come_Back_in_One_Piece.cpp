#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 100'000;
const ll MAX_M = 200'000;
ll N, M;
vector<ll> G[MAX_N];
vector<ll> GT[MAX_N];
ll terminated[MAX_N];
bool used[MAX_N];
bool used_T[MAX_N];

void dfs(ll u, ll &t) {
  for (auto v : G[u]) {
    if (!used[v]) {
      used[v] = true;
      dfs(v, ++t);
    }
  }
  terminated[u] = ++t;
}

ll dfs_T(ll u) {
  ll n_vs = 0;
  for (auto v : GT[u]) {
    if (!used_T[v]) {
      used_T[v] = true;
      n_vs += dfs_T(v);
    }
  }
  return n_vs + 1;
}

int main() {
  cin >> N >> M;
  set<pll> P;
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    P.insert({a, b});
  }
  for (auto p : P) {
    G[p.first].push_back(p.second);
    GT[p.second].push_back(p.first);
  }
  ll t = 0;
  for (ll u = 0; u < N; ++u) {
    if (!used[u]) {
      used[u] = true;
      dfs(u, t);
    }
  }
  for (ll u = 0; u < N; ++u) {
    sort(GT[u].begin(), GT[u].end(), [](const ll a, const ll b) {
      return terminated[a] > terminated[b];
    });
  }
  ll res = 0;
  vector<pll> V;
  for (ll u = 0; u < N; ++u) {
    V.push_back({terminated[u], u});
  }
  sort(V.begin(), V.end());
  for (ll i = V.size() - 1; i >= 0; --i) {
    ll u = V[i].second;
    if (!used_T[u]) {
      used_T[u] = true;
      ll n_vs = dfs_T(u);
      res += n_vs * (n_vs - 1) / 2;
    }
  }
  printf("%lld\n", res);
}