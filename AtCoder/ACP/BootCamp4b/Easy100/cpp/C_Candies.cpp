#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int A[MAX_N][MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int t = 0;
    for (int j = 0; j <= i; ++j) {
      t += A[0][j];
    }
    for (int j = i; j < N; ++j) {
      t += A[1][j];
    }
    res = max(res, t);
  }
  printf("%d\n", res);
}