#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int A[MAX_N];

int main() {
  int N, x;
  cin >> N >> x;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] <= x) {
      ++cnt;
      x -= A[i];
    } else {
      printf("%d\n", cnt);
      return 0;
    }
  }
  if (x > 0) {
    printf("%d\n", cnt - 1);
  } else {
    printf("%d\n", cnt);
  }
}