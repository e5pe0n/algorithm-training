#include <iostream>
#include <stdio.h>

#define MAX_N 100'001

using namespace std;

int A[MAX_N]{};

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int M = N - K;
  int res = 1;
  if (M > 0) {
    res += (int)(M / (K - 1)) + (M % (K - 1) != 0);
  }
  printf("%d\n", res);
}