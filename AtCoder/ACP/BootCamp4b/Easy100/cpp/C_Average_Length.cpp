#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 8

using namespace std;

int X[MAX_N];
int Y[MAX_N];
int A[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
    A[i] = i;
  }
  double d = 0;
  int cnt = 0;
  do {
    double _d = 0;
    for (int i = 0; i < N - 1; ++i) {
      _d += sqrt((X[A[i]] - X[A[i + 1]]) * (X[A[i]] - X[A[i + 1]]) +
                 (Y[A[i]] - Y[A[i + 1]]) * (Y[A[i]] - Y[A[i + 1]]));
    }
    d += _d;
    ++cnt;
  } while (next_permutation(A, A + N));
  printf("%f\n", d / cnt);
}