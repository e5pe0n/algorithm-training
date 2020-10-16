#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int N;
int A[MAX_N]{};
int B[MAX_N]{};
int C[MAX_N]{};

ll A_B[MAX_N]{};
ll B_C[MAX_N]{};

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }
  if (N == 1) {
    printf("%d\n", A[0] < B[0] && B[0] < C[0]);
    return 0;
  }
  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);
  int i = 0;
  int idx = 0;
  while (i < N && idx < N) {
    while (i < N && idx < N && C[i] <= B[idx]) {
      ++i;
    }
    while (i < N && idx < N && C[i] > B[idx]) {
      B_C[idx++] = N - i;
    }
  }
  i = N - 1;
  idx = N - 1;
  while (idx > 0) {
    while ((i >= 0 && idx > 0 && A[idx] >= B[i]) || (i < 0 && idx > 0)) {
      --idx;
      A_B[idx] = A_B[idx + 1];
    }
    while (i >= 0 && idx >= 0 && A[idx] < B[i]) {
      A_B[idx] += B_C[i--];
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += A_B[i];
  }
  printf("%lld\n", ans);
}