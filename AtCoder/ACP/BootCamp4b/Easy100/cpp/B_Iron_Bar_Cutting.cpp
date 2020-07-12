#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'001
#define INF 1'000'000'000'000'000'000

typedef long long ll;

using namespace std;

ll A[MAX_N];
ll _A[MAX_N];

int main() {
  int N;
  cin >> N;
  ll L = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    L += A[i];
  }
  ll res = INF;
  _A[0] = 0;
  for (int i = 0; i < N - 1; ++i) {
    _A[i + 1] = _A[i] + A[i];
    res = min(res, abs(_A[i + 1] - L + _A[i + 1]));
  }
  printf("%lld\n", res);
}