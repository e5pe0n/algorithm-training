#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
#define MAX_K 100'000
using namespace std;
typedef long long ll;

ll N, M, K;
ll A[MAX_M], B[MAX_M];
ll C[MAX_K], D[MAX_K];

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
  init();
  map<ll, ll> F;
  for (ll i = 0; i < M; ++i) {
    unite(A[i], B[i]);
    ++F[A[i]];
    ++F[B[i]];
  }
  for (ll i = 0; i < N; ++i) {
    find(i);
  }
  map<ll, ll> G;
  for (ll i = 0; i < N; ++i) {
    ++G[par[i]];
  }
  vector<ll> V(N);
  for (ll i = 0; i < N; ++i) {
    V[i] = G[par[i]] - F[i] - 1;
  }
  for (ll i = 0; i < K; ++i) {
    if (same(C[i], D[i])) {
      --V[C[i]];
      --V[D[i]];
    }
  }
  for (ll i = 0; i < N; ++i) {
    printf("%lld%c", V[i], i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  cin >> N >> M >> K;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  for (ll i = 0; i < K; ++i) {
    cin >> C[i] >> D[i];
    --C[i];
    --D[i];
  }
  solve();
}