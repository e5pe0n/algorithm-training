#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(A, A + N);
  int res = 0;
  for (int i = N - 1; i >= 0; i -= 2) {
    res += A[i];
  }
  for (int i = N - 2; i >= 0; i -= 2) {
    res -= A[i];
  }
  printf("%d\n", res);
}