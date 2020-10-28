#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100
#define MAX_W 10'000

using namespace std;

int N, W;
int w[MAX_N]{}, v[MAX_N]{};
int dp[MAX_N + 1][MAX_W + 1]{};

int main() {
  ifstream ifs("../testset/zero_one_knapsack_problem/test1.txt");
  ifs >> N >> W;
  for (int i = 0; i < N; ++i) {
    ifs >> w[i] >> v[i];
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j <= W; ++j) {
      if (j < w[i]) {
        dp[i][j] = dp[i + 1][j];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  printf("%d\n", dp[0][W]);
}