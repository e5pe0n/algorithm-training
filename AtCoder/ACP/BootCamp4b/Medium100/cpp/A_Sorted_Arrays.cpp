#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int i = 0;
  int cnt = 0;
  while (i < N) {
    while (i < N - 1 && A[i + 1] == A[i]) {
      ++i;
    }
    if (i >= N - 1) {
      ++cnt;
      printf("%d\n", cnt);
      return 0;
    }
    if (A[i + 1] < A[i]) {
      while (i < N - 1 && A[i + 1] <= A[i]) {
        ++i;
      }
    } else {
      while (i < N - 1 && A[i + 1] >= A[i]) {
        ++i;
      }
    }
    ++cnt;
    ++i;
  }
  printf("%d\n", cnt);
}