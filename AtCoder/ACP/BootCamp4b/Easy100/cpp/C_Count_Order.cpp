#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 8

using namespace std;

int P[MAX_N];
int Q[MAX_N];

int main() {
  int N;
  cin >> N;
  int *A;
  int *B;
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> Q[i];
  }

  int _cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (P[i] < Q[i]) {
      A = P;
      B = Q;
      break;
    } else if (Q[i] < P[i]) {
      A = Q;
      B = P;
      break;
    }
    ++_cnt;
  }
  if (_cnt == N) {
    printf("0\n");
    return 0;
  }

  int cnt = 0;
  do {
    bool flg = true;
    for (int i = 0; i < N; ++i) {
      if (A[i] != B[i]) {
        flg = false;
        break;
      }
    }
    if (flg) {
      printf("%d\n", cnt);
      return 0;
    }
    ++cnt;
  } while (next_permutation(A, A + N));
}