#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int A[MAX_N]{};

int main() {
  int N, K;
  cin >> N >> K;
  bool found = false;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] == K) {
      found = true;
    }
  }
  sort(A, A + N);
  int max_a = A[N - 1];
  int min_diff = A[N - 1];
  for (int i = 0; i < N - 1; ++i) {
    int diff = A[i + 1] - A[i];
    if (diff > 0) {
      min_diff = min(min_diff, diff);
    }
  }
  if (found || (K <= max_a && K % min_diff == 0)) {
    printf("POSSIBLE\n");
  } else {
    printf("IMPOSSIBLE\n");
  }
}