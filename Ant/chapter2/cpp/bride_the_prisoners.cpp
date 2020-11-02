#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_Q 100
#define INF 1'000'000'000

using namespace std;

int P, Q;
int A[MAX_Q + 2];
int dp[MAX_Q + 1][MAX_Q + 2];

int main() {
  ifstream ifs("../testset/bride_the_prisoners/test2.txt");
  ifs >> P >> Q;
  A[0] = 0;
  for (int i = 1; i <= Q; ++i) {
    ifs >> A[i];
  }
  A[Q + 1] = P + 1;
  for (int i = 0; i <= Q; ++i) {
    dp[i][i + 1] = 0;
  }
  for (int w = 2; w <= Q + 1; ++w) {
    for (int i = 0; i + w <= Q + 1; ++i) {
      int j = i + w;
      int t = INF;
      for (int k = i + 1; k < j; ++k) {
        t = min(t, dp[i][k] + dp[k][j]);
      }
      dp[i][j] = t + A[j] - A[i] - 2;
    }
  }
  printf("%d\n", dp[0][Q + 1]);
}