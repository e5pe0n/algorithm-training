#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int n = 1;
  for (int i = 0; i < N; ++i) {
    n = min(n * 2, n + K);
  }
  printf("%d\n", n);
}