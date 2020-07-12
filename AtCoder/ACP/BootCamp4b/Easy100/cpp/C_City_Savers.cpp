#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'001

using namespace std;

int A[MAX_N];
int _A[MAX_N];
int B[MAX_N];
int _B[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i <= N; ++i) {
    cin >> A[i];
    _A[i] = A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
    _B[i] = B[i];
  }
  int cnt = 0;
  for (int i = N - 1; i >= 0; --i) {
    cnt += min(B[i], A[i + 1]);
    B[i] = max(0, B[i] - A[i + 1]);
    cnt += min(B[i], A[i]);
    A[i] = max(0, A[i] - B[i]);
  }
  int _cnt = 0;
  for (int i = 0; i < N; ++i) {
    _cnt += min(_B[i], _A[i]);
    _B[i] = max(0, _B[i] - _A[i]);
    _cnt += min(_B[i], _A[i + 1]);
    _A[i + 1] = max(0, _A[i + 1] - _B[i]);
  }
  printf("%d\n", max(cnt, _cnt));
}