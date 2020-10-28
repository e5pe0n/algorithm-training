#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100
#define MAX_V 100
#define INF 2'000'000'000

using namespace std;

int N, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

int main() {
  ifstream ifs("../testset/zero_one_knapsack_problem/test1.txt");
  ifs >> N >> W;
  for (int i = 0; i < N; ++i) {
    ifs >> w[i] >> v[i];
  }
  int V = MAX_N * MAX_V;
  fill(dp[0], dp[0] + V + 1, INF);
  dp[0][0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= V; ++j) {
      if (j < v[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }
  int res = 0;
  for (int j = 0; j <= V; ++j) {
    if (dp[N][j] <= W) {
      res = j;
    }
  }
  printf("%d\n", res);
}