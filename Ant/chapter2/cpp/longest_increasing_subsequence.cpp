#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 1000

using namespace std;

int N, res;
int A[MAX_N], dp[MAX_N];

int main() {
  ifstream ifs("../testset/longest_increasing_subsequence/test1.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  printf("%d\n", res);
}