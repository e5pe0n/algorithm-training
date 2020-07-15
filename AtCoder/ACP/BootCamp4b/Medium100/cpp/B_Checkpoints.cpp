#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 50
#define INF 1'000'000'000'000'000'000

typedef long long ll;

using namespace std;

int A[MAX_N];
int B[MAX_N];
int C[MAX_N];
int D[MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> C[i] >> D[i];
  }
  for (int i = 0; i < N; ++i) {
    ll d = INF;
    int res = 0;
    for (int j = 0; j < M; ++j) {
      ll _d = (ll)abs(A[i] - C[j]) + (ll)abs(B[i] - D[j]);
      if (_d < d) {
        d = _d;
        res = j + 1;
      }
    }
    printf("%d\n", res);
  }
}