#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int f(int n) {
  int cnt = 0;
  for (int i = 1; i < (int)sqrt(n) + 1; ++i) {
    if (n % i == 0) {
      ++cnt;
      if (i != (int)(n / i)) {
        ++cnt;
      }
    }
  }
  return cnt;
}

int main() {
  int N;
  cin >> N;
  int64_t res = 0;
  for (int i = 1; i <= N; ++i) {
    res += i * f(i);
  }
  printf("%lld\n", res);
}