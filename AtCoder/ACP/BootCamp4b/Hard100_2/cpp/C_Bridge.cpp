#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_M 50
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_M], B[MAX_M];

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

void solve() {
  ll res = 0;
  for (ll i = 0; i < M; ++i) {
    init();
    for (ll j = 0; j < M; ++j) {
      if (i == j) continue;
      unite(A[j], B[j]);
    }
    for (ll j = 0; j < N; ++j) {
      find(j);
    }
    for (ll j = 0; j < N - 1; ++j) {
      if (par[j + 1] != par[j]) {
        ++res;
        break;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  solve();
}