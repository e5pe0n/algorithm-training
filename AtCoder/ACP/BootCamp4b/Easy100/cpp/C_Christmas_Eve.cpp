#include <algorithm>
#include <iostream>
#include <math.h>
#include <memory>
#include <stdio.h>

#define MAX_N 100'000
#define MAX_H 1'000'000'000

using namespace std;

int H[MAX_N];
bool B[MAX_N];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  sort(H, H + N);
  int res = MAX_H;
  for (int i = 0; i < N - K + 1; ++i) {
    int _h = MAX_H;
    int h = 0;
    for (int j = i; j < i + K; ++j) {
      _h = min(_h, H[j]);
      h = max(h, H[j]);
    }
    res = min(res, h - _h);
    if (res == 0) {
      break;
    }
  }
  printf("%d\n", res);
}