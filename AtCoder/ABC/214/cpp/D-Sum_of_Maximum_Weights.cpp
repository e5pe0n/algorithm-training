#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;

ll N;
vector<ll> E[MAX_N];
ll par[MAX_N], rnk[MAX_N], cnt[MAX_N];

void init() {
  for (ll i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
    cnt[i] = 1;
  }
}

ll find(ll u) {
  if (par[u] == u) return u;
  return par[u] = find(par[u]);
}

void unite(ll u, ll v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (rnk[u] < rnk[v]) {
    par[u] = v;
  } else {
    par[v] = u;
    if (rnk[u] == rnk[v]) ++rnk[u];
  }
  ll c = cnt[u] + cnt[v];
  cnt[u] = cnt[v] = c;
}

int main() {
  cin >> N;
  init();
  for (ll i = 0; i < N - 1; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    E[i] = {w, min(u, v), max(u, v)};
  }
  sort(E, E + N - 1);
  ll res = 0;
  for (ll i = 0; i < N - 1; ++i) {
    vector<ll> vec = E[i];
    ll w = vec[0];
    ll u = vec[1];
    ll v = vec[2];
    res += cnt[find(u)] * cnt[find(v)] * w;
    unite(u, v);
  }
  printf("%lld\n", res);
}