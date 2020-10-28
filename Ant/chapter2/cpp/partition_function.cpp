#include <fstream>
#include <stdio.h>

#define MAX_M 10000
#define MAX_N 1000

using namespace std;

int n, m, M;
int dp[MAX_M + 1][MAX_N + 1]{};

int main() {
  ifstream ifs("../testset/partition_function/test1.txt");
  ifs >> n >> m >> M;
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j - i >= 0) {
        dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  printf("%d\n", dp[m][n]);
}