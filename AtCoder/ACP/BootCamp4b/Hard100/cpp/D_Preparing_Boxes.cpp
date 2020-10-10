#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int A[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int M = 0;
  for (int i = N; i > 0; --i) {
    int t = 0;
    for (int j = i; j <= N; j += i) {
      t += A[j - 1];
    }
    if (t % 2 != A[i - 1]) {
      A[i - 1] = (A[i - 1] + 1) % 2;
    }
    if (A[i - 1]) {
      ++M;
    }
  }
  printf("%d\n", M);
  if (M > 0) {
    for (int i = 0; i < N; ++i) {
      if (A[i]) {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  }
}