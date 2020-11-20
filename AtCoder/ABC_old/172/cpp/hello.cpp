#include <iostream>
#include <stdio.h>

using namespace std;

int f(int n) {
  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    ret *= i;
  }
  return ret;
}

int C(int n, int r) { return f(n) / (f(n - r) * f(r)); }

int main() {
  int N, M;
  cin >> N >> M;
  int fN = f(N);
  int fM = f(M);
  int res = C(M, N);
  printf("%d %d %d\n", fN, fM, res);
}