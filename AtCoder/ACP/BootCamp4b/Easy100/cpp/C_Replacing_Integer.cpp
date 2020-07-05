#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;
  printf("%lld\n", min(N % K, abs(N % K - K)));
}