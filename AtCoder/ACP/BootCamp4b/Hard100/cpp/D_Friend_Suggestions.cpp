#include <iostream>
#include <stdio.h>

#define MAX_N 100'000
#define MAX_M 100'000
#define MAX_K 100'000

using namespace std;

int N, M, K;
int A[MAX_M]{};
int B[MAX_M]{};
int C[MAX_K]{};
int D[MAX_K]{};

int CC1[MAX_N]{};
int CC2[MAX_N]{};

int par[MAX_N]{};
int rnk[MAX_N]{};

void init() {
  for (int i = 0; i < N; ++i) {
    par[i] = i;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  }
  par[x] = find(par[x]);
  return par[x];
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

int main() {
  cin >> N >> M >> K;
  init();
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    A[i] = a - 1;
    B[i] = b - 1;
  }
  for (int i = 0; i < K; ++i) {
    int c, d;
    cin >> c >> d;
    C[i] = c - 1;
    D[i] = d - 1;
  }
  for (int i = 0; i < M; ++i) {
    unite(A[i], B[i]);
  }
  for (int i = 0; i < N; ++i) {
    int p = find(i);
    ++CC1[p];
  }
  for (int i = 0; i < N; ++i) {
    CC2[i] = CC1[par[i]] - 1;
  }
  for (int i = 0; i < M; ++i) {
    --CC2[A[i]];
    --CC2[B[i]];
  }
  for (int i = 0; i < K; ++i) {
    if (same(C[i], D[i])) {
      --CC2[C[i]];
      --CC2[D[i]];
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%d ", CC2[i]);
  }
  printf("\n");
}