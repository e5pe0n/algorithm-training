#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000
#define INF 1'000'000'000'000

using namespace std;

int A[MAX_N];
int B[MAX_N];
int D[MAX_N][MAX_N];

int main() {
  int K, N;
  cin >> K >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    B[i] = i;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      D[i][j] = min(abs(A[j] - A[i]), abs(A[i] + (K - A[j])));
    }
  }

  int64_t res = INF;
  do {
    int64_t d = 0;
    for (int i = 0; i < N - 1; ++i) {
      d += D[B[i + 1]][B[i]];
    }
    res = min(res, d);
  } while (next_permutation(B, B + N));
  printf("%lld\n", res);
}