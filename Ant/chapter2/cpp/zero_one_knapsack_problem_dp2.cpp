#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100
#define MAX_W 10'000

using namespace std;

int N, W;
int w[MAX_N]{}, v[MAX_N]{};
int dp[MAX_W + 1]{};

int main() {
  ifstream ifs("../testset/zero_one_knapsack_problem/test1.txt");
  ifs >> N >> W;
  for (int i = 0; i < N; ++i) {
    ifs >> w[i] >> v[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = W; j >= w[i]; --j) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  printf("%d\n", dp[W]);
}