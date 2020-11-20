#include <bitset>
#include <iostream>
#include <stdio.h>

#define MAX_M 500'000
#define D 1'000'000'007

using namespace std;

int64_t f(int n) {
  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    ret *= i;
  }
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;

  int64_t res = (N - 1) * (f(M - 2) + N) + (M - N) * ((N - 1) * N + f(M - N)) * f(M) / (f(M - N) * f(N));
  printf("%lld\n", res % D);
}