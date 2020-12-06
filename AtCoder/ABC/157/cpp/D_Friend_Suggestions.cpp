#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
#define MAX_K 100'000
using namespace std;

int N, M, K;
int F[MAX_N], G[MAX_N];
int A[MAX_M], B[MAX_M], C[MAX_K], D[MAX_K];

int par[MAX_N], rnk[MAX_N];

void init() {
  for (int i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (x == par[x]) {
    return x;
  }
  return par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (rnk[y] > rnk[x]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) {
      ++rnk[x];
    }
  }
}

bool same(int x, int y) { return find(x) == find(y); }

void solve() {
  init();
  for (int i = 0; i < M; ++i) {
    unite(A[i], B[i]);
    ++F[A[i]];
    ++F[B[i]];
  }
  for (int i = 0; i < N; ++i) {
    find(i);
  }
  map<int, int> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[par[i]];
  }
  for (int i = 0; i < K; ++i) {
    if (same(C[i], D[i])) {
      ++G[C[i]];
      ++G[D[i]];
    }
  }
  for (int i = 0; i < N; ++i) {
    int res = max(0, cnt[par[i]] - 1 - F[i] - G[i]);
    printf("%d%c", res, i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  for (int i = 0; i < K; ++i) {
    cin >> C[i] >> D[i];
    --C[i];
    --D[i];
  }
  solve();
}