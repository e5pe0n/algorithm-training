#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_T 100

using namespace std;

int A[MAX_T]{};

int main() {
  int K, T;
  cin >> K >> T;
  for (int i = 0; i < T; ++i) {
    cin >> A[i];
  }
  sort(A, A + T);
  int t = 0;
  for (int i = 0; i < T - 1; ++i) {
    t += A[i];
  }
  int ans = max(0, A[T - 1] - t - 1);
  printf("%d\n", ans);
}