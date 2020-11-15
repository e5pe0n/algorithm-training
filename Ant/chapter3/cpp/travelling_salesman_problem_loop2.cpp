#include <algorithm>
#include <fstream>
#include <stdio.h>

using namespace std;

#define MAX_N 15
#define INF 1'000'000'000

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
  dp[0][0] = 0;
  for (int S = 1; S < 1 << n; ++S) {
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        dp[S][v] = min(dp[S][v], dp[S & ~(1 << v)][u] + d[u][v]);
      }
    }
  }
  printf("%d\n", dp[(1 << n) - 1][0]);
}
