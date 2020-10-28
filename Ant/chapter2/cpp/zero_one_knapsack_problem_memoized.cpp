#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_N 100
#define MAX_W 10'000

using namespace std;

int N, W;
int w[MAX_N]{}, v[MAX_N]{};
int dp[MAX_N + 1][MAX_W + 1];

int rec(int i, int j) {
  if (dp[i][j] >= 0) {
    return dp[i][j];
  }
  int res = 0;
  if (i == N) {
    res = 0;
  } else if (j < w[i]) {
    res = rec(i + 1, j);
  } else {
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  return dp[i][j] = res;
}

int main() {
  ifstream ifs("../testset/zero_one_knapsack_problem/test1.txt");
  ifs >> N >> W;
  for (int i = 0; i < N; ++i) {
    ifs >> w[i] >> v[i];
  }
  memset(dp, -1, sizeof(dp));
  int res = rec(0, W);
  printf("%d\n", res);
}