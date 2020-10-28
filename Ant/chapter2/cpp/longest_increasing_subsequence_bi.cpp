#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 1000
#define INF 2'000'000'000

using namespace std;

int N;
int A[MAX_N], dp[MAX_N];

int main() {
  ifstream ifs("../testset/longest_increasing_subsequence/test2.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  fill(dp, dp + N, INF);
  for (int i = 0; i < N; ++i) {
    *lower_bound(dp, dp + N, A[i]) = A[i];
  }
  printf("%d\n", (int)(lower_bound(dp, dp + N, INF) - dp));
}