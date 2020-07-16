#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  double res = 0;
  for (int i = 1; i <= min(N, K - 1); ++i) {
    res += pow(0.5, ceil(log2(ceil((double)K / i))));
  }
  printf("%.10f\n", (res + max(0, N - K + 1)) / N);
}