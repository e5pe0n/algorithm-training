#include <iostream>
#include <memory>
#include <stdio.h>

using namespace std;

int A[3]{};

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    A[i] = -1;
  }
  bool flg = true;
  for (int i = 0; i < M; ++i) {
    int s, c;
    cin >> s >> c;
    if (A[s - 1] == -1 || A[s - 1] == c) {
      A[s - 1] = c;
    } else {
      flg = false;
    }
    if (N > 1 && s == 1 && c == 0) {
      flg = false;
    }
  }
  if (!flg) {
    printf("-1\n");
    return 0;
  }
  if (A[0] == -1) {
    if (N > 1) {
      A[0] = 1;
    } else {
      A[0] = 0;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (A[i] == -1) {
      A[i] = 0;
    }
    printf("%d", A[i]);
  }
  printf("\n");
}