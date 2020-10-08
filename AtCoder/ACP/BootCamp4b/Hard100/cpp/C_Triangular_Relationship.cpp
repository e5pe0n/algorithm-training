#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int64_t ans = (int64_t)pow((double)(N / K), 3);
  if (K % 2 == 0) {
    ans += (int64_t)pow((double)((N + K / 2) / K), 3);
  }
  printf("%ld\n", ans);
}