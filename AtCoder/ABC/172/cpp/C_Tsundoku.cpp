#include <iostream>
#include <stdio.h>

#define MAX_N 200'000
#define MAX_A 1'000'000'001
using namespace std;

int A[MAX_N];
int B[MAX_N];

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }

  int iA = 0;
  int iB = 0;
  int cnt = 0;
  int64_t _K = 0;
  while (true) {
    int a = MAX_A;
    int b = MAX_A;
    if (iA >= N && iB >= M) {
      printf("%d\n", cnt);
      return 0;
    }
    if (iA < N) {
      a = A[iA];
    }
    if (iB < M) {
      b = B[iB];
    }
    if (a < b) {
      _K += a;
      ++iA;
    } else {
      _K += b;
      ++iB;
    }
    if (_K > K) {
      printf("%d\n", cnt);
      return 0;
    }
    ++cnt;
  }
}
