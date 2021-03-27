#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll P[MAX_N];
ll X[MAX_M], Y[MAX_M];

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

int main() {
  cin >> N >> M;
  init();
  for (ll i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }
  for (ll i = 0; i < M; ++i) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
    unite(X[i], Y[i]);
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (same(i, P[i])) ++res;
  }
  printf("%lld\n", res);
}