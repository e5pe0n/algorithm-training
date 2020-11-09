#include <algorithm>
#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_n 8
#define MAX_m 30
#define INF 1e18

using namespace std;

int n, m, k, a, b;
int t[MAX_n];
int d[MAX_n][MAX_n];
double dp[1 << MAX_n][MAX_m];

int main() {
  ifstream ifs("../testset/travelling_by_stagecoach/test1.txt");
  ifs >> n >> m >> k >> a >> b;
  --a;
  --b;
  for (int i = 0; i < n; ++i) {
    ifs >> t[i];
  }
  for (int i = 0; i < m; ++i) {
    fill(d[i], d[i] + m, -1);
  }
  for (int i = 0; i < k; ++i) {
    int u, v, w;
    ifs >> u >> v >> w;
    --u;
    --v;
    d[u][v] = w;
    d[v][u] = w;
  }
  for (int i = 0; i < 1 << n; ++i) {
    fill(dp[i], dp[i] + m, INF);
  }
  dp[(1 << n) - 1][a] = 0;
  double res = INF;
  for (int S = (1 << n) - 1; S >= 0; --S) {
    res = min(res, dp[S][b]);
    for (int v = 0; v < m; ++v) {
      for (int i = 0; i < n; ++i) {
        if (S >> i & 1) {
          for (int u = 0; u < m; ++u) {
            if (d[v][u] >= 0) {
              dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
            }
          }
        }
      }
    }
  }
  if (res == INF) {
    printf("Impossible\n");
  } else {
    printf("%.3f\n", res);
  }
}