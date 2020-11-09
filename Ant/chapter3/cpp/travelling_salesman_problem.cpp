#include <algorithm>
#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <string>

#define MAX_N 15
#define INF 1'000'000'000

using namespace std;

int n, m;
int d[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

string d2b(int n, int m) {
  string res;
  while (n > 0) {
    if (n % 2 == 0) {
      res = "0" + res;
    } else {
      res = "1" + res;
    }
    n >>= 1;
  }
  int _m = res.size();
  for (int i = 0; _m + i < m; ++i) {
    res = "0" + res;
  }
  return res;
}

int rec(int S, int v) {
  if (dp[S][v] >= 0) {
    return dp[S][v];
  }
  if (S == (1 << n) - 1 && v == 0) {
    return dp[S][v] = 0;
  }
  int res = INF;
  for (int u = 0; u < n; ++u) {
    if (!(S >> u & 1)) {
      res = min(res, rec(S | 1 << u, u) + d[v][u]);
    }
  }
  return dp[S][v] = res;
}

int main() {
  ifstream ifs("../testset/travelling_salesman_problem/test1.txt");
  ifs >> n >> m;
  fill(&d[0][0], &d[0][0] + sizeof(d), INF);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    ifs >> u >> v >> w;
    d[u][v] = w;
  }

  memset(dp, -1, sizeof(dp));
  printf("%d\n", rec(0, 0));
}