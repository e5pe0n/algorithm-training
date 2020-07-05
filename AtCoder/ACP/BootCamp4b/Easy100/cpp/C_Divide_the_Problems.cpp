#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int D[MAX_N];

int main() {
  int N;
  cin >> N;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    cin >> D[i];
  }
  sort(D, D + N);
  res = D[(N - 1) / 2 + 1] - D[(N - 1) / 2];
  printf("%d\n", res);
}