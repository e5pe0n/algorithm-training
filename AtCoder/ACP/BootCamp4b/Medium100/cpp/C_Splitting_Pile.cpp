#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 200'000
#define INF 1'000'000'000'000'000'000

typedef long long ll;

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  ll t = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    t += A[i];
  }
  ll res = INF;
  ll s = 0;
  for (int i = 0; i < N - 1; ++i) {
    s += A[i];
    res = min(res, abs(t - s - s));
  }
  printf("%lld\n", res);
}