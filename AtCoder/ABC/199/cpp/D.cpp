#include <bits/stdc++.h>
#define MAX_N 20
#define MAX_M (MAX_N) * (MAX_N - 1) / 2
using namespace std;
using ll = long long;

ll N, M;
vector<ll> G[MAX_N];
ll par[MAX_N], rnk[MAX_N];

void init() {
  for (ll i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y])
    par[x] = y;
  else {
    par[y] = x;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
}

bool same(ll x, ll y) {
  return find(x) == find(y);
}

ll bfs(ll s) {
  queue<ll> q;
  q.push(s);
  vector<ll> colors(N);
  vector<bool> used(N);
  while (q.size()) {
    ll u = q.front();
    q.pop();
    used[u] = true;
    ll cnt = 0;
    for (auto v : G[u]) {
      if (colors[v] > 0) ++cnt;
      if (!used[v]) q.push(v);
    }
    if (cnt >= 3) return 0;
    colors[u] = 3 - cnt;
  }
  ll res = 1;
  for (ll i = 0; i < N; ++i) {
    if (used[i]) res *= colors[i];
  }
  return res;
}

int main() {
  cin >> N >> M;
  init();
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
    unite(a, b);
  }
  map<ll, vector<ll>> C;
  for (ll i = 0; i < N; ++i) {
    C[find(i)].push_back(i);
  }
  ll res = 1;
  for (auto p : C) {
    res *= bfs(p.first);
  }
  printf("%lld\n", res);
}