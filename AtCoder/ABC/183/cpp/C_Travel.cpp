#include <iostream>
#include <stdio.h>

#define MAX_N 8

using namespace std;

int N, K;
int T[MAX_N][MAX_N];

int dfs(int u, int S, int t) {
  if (S == (1 << N) - 1 && u == 0 && t == K) {
    return 1;
  }
  int res = 0;
  for (int v = 0; v < N; ++v) {
    if (!(S >> v & 1)) {
      res += dfs(v, S | 1 << v, t + T[u][v]);
    }
  }
  return res;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> T[i][j];
    }
  }
  int res = dfs(0, 0, 0);
  printf("%d\n", res);
}