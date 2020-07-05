// LTE
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000
#define INF 1'000'000'000

using namespace std;

int A[MAX_N];
int D[MAX_N];

int main() {
  int K, N;
  cin >> K >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (int i = 0; i < N - 1; ++i) {
    D[i] = min(abs(A[i + 1] - A[i]), abs(A[i] + (K - A[i - 1])));
  }
  D[N - 1] = min(abs(A[N - 1] - A[0]), abs(A[0] + (K - A[N - 1])));

  int res = INF;
  for (int i = 0; i < N; ++i) {
    int d = 0;
    int j = i;
    int k = (j + 1) % N;
    while (k != i) {
      d += k - j == 1 ? D[j] : D[N - 1];
      j = k;
      k = (j + 1) % N;
    }
    res = min(res, d);
    d = 0;
    j = i;
    k = (j - 1 + N) % N;
    while (k != i) {
      d += k - j == -1 ? D[k] : D[N - 1];
      j = k;
      k = (j - 1 + N) % N;
    }
    res = min(res, d);
  }
  printf("%d\n", res);
}