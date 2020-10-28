#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <string>

#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int N, M;
string S, T;
int dp[MAX_N + 1][MAX_M + 1]{};

int main() {
  ifstream ifs("../testset/longest_common_subsequence/test1.txt");
  ifs >> N >> S >> M >> T;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (S[i] == T[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  printf("%d\n", dp[N][M]);
}