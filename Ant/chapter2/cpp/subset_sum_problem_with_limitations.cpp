#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_N 100
#define MAX_K 100'000

using namespace std;

int N, K;
int A[MAX_N], M[MAX_N];
int dp[MAX_K + 1];

int main() {
  ifstream ifs("../testset/subset_sum_problem_with_limitations/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i] >> M[i];
  }
  memset(dp, -1, K + 1);
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= K; ++j) {
      if (dp[j] >= 0) {
        dp[j] = M[i];
      } else if (j < A[i] || dp[j - A[i]] < 0) {
        dp[j] = -1;
      } else {
        dp[j] = dp[j - A[i]] - 1;
      }
    }
  }
  if (dp[K] >= 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}