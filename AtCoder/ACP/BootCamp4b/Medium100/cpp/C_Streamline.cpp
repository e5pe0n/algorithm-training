#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_M 100'001

typedef long long ll;

using namespace std;

int X[MAX_M];
int _X[MAX_M];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> X[i];
  }
  if (M == 1) {
    printf("0\n");
    return 0;
  }
  sort(X, X + M);
  ll res = 0;
  for (int i = 0; i < M - 1; ++i) {
    _X[i] = X[i + 1] - X[i];
    res += _X[i];
  }
  sort(_X, _X + M - 1);
  for (int i = 0; i < min(N - 1, M - 1); ++i) {
    res -= _X[M - 2 - i];
  }
  printf("%lld\n", res);
}