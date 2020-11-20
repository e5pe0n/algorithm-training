#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'001

using namespace std;

int64_t A[MAX_N];
int64_t B[MAX_N];

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= M; ++i) {
    cin >> B[i];
  }

  A[0] = 0;
  B[0] = 0;
  for (int i = 0; i < N; ++i) {
    A[i + 1] += A[i];
  }
  for (int i = 0; i < M; ++i) {
    B[i + 1] += B[i];
  }

  int res = 0;
  int j = M;
  for (int i = 0; i <= N; ++i) {
    if (A[i] > K) {
      break;
    }
    while (B[j] > K - A[i]) {
      --j;
    }
    res = max(res, i + j);
  }
  printf("%d\n", res);
}