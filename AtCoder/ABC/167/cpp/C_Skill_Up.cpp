#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 12
#define MAX_M 12
using namespace std;

int N, M, X;
int C[MAX_N], A[MAX_N][MAX_M];
int x[MAX_M];

void solve() {
  int res = INF;
  for (int i = 1; i < 1 << N; ++i) {
    memset(x, 0, sizeof(x));
    int c = 0;
    for (int j = 0; j < N; ++j) {
      if (i >> j & 1) {
        c += C[j];
        for (int k = 0; k < M; ++k) {
          x[k] += A[j][k];
        }
      }
    }
    bool f = true;
    for (int j = 0; j < M; ++j) {
      if (x[j] < X) {
        f = false;
        break;
      }
    }
    if (f) {
      res = min(res, c);
    }
  }
  if (res == INF) {
    res = -1;
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> M >> X;
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }
  solve();
}