#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int A[MAX_N];
int D[MAX_N];

int main() {
  int K, N;
  cin >> K >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  int max_d = 0;
  int max_idx = 0;
  for (int i = 0; i < N - 1; ++i) {
    D[i] = min(abs(A[i + 1] - A[i]), abs(A[i] + (K - A[i + 1])));
    if (max_d < D[i]) {
      max_d = D[i];
      max_idx = i;
    }
  }
  D[N - 1] = min(abs(A[N - 1] - A[0]), abs(A[0] + (K - A[N - 1])));
  if (max_d < D[N - 1]) {
    max_idx = N - 1;
  }

  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (i != max_idx) {
      res += D[i];
    }
  }
  printf("%d\n", res);
}