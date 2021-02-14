#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 10000
using namespace std;
typedef long long ll;

ll N, M;
ll U[MAX_M], V[MAX_M];
ll par[MAX_N], rnk[MAX_N];

void init() {
  for (ll i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
}

bool same(ll x, ll y) {
  return find(x) == find(y);
}

int main() {
  cin >> N >> M;
  init();
  for (ll i = 0; i < M; ++i) {
    cin >> U[i] >> V[i];
    --U[i];
    --V[i];
    unite(U[i], V[i]);
  }
  for (ll i = 0; i < N; ++i) {
    find(i);
  }
  map<ll, ll> C;
  for (ll i = 0; i < N; ++i) {
    ++C[par[i]];
  }
  map<ll, ll> C2;
  for (ll i = 0; i < M; ++i) {
    ++C2[par[U[i]]];
  }
  ll res = 0;
  for (auto p : C) {
    ll ver = p.second;
    ll edge = C2[p.first];
    if (ver - 1 == edge) ++res;
  }
  printf("%lld\n", res);
}