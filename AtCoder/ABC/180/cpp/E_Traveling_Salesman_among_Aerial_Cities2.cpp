#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 17
#define INF 1'000'000'000

using namespace std;

int N;
int X[MAX_N], Y[MAX_N], Z[MAX_N];
int d[1 << MAX_N][MAX_N];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  for (int i = 0; i < 1 << N; ++i) {
    fill(d[i], d[i] + N, INF);
  }
  d[0][0] = 0;
  for (int S = 1; S < 1 << N; ++S) {
    for (int u = 0; u < N; ++u) {
      for (int v = 0; v < N; ++v) {
        d[S][v] =
            min(d[S][v], d[S & ~(1 << v)][u] + abs(X[v] - X[u]) + abs(Y[v] - Y[u]) + max(0, Z[v] - Z[u]));
      }
    }
  }
  printf("%d\n", d[(1 << N) - 1][0]);
}