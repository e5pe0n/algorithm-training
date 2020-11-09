#include <algorithm>
#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_N 15
#define INF 1'000'000'000

using namespace std;

int n, m;
int d[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int main() {
  ifstream ifs("../testset/travelling_salesman_problem/test1.txt");
  ifs >> n >> m;
  for (int i = 0; i < n; ++i) {
    fill(d[i], d[i] + n, INF);
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    ifs >> u >> v >> w;
    d[u][v] = w;
  }

  for (int S = 0; S < 1 << n; ++S) {
    fill(dp[S], dp[S] + n, INF);
  }
  dp[(1 << n) - 1][0] = 0;
  for (int S = (1 << n) - 2; S >= 0; --S) {
    for (int v = 0; v < n; ++v) {
      for (int u = 0; u < n; ++u) {
        if (!(S >> u & 1)) {
          dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
        }
      }
    }
  }
  printf("%d\n", dp[0][0]);
}