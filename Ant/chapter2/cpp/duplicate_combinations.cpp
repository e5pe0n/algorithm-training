#include <fstream>
#include <stdio.h>

#define MAX_n 1000
#define MAX_m 1000

using namespace std;

int n, m, M;
int a[MAX_n], dp[MAX_n + 1][MAX_m + 1]{};

int main() {
  ifstream ifs("../testset/duplicate_combinations/test1.txt");
  ifs >> n >> m >> M;
  for (int i = 0; i < n; ++i) {
    ifs >> a[i];
  }
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j - 1 - a[i] >= 0) {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
      }
    }
  }
  printf("%d\n", dp[n][m]);
}