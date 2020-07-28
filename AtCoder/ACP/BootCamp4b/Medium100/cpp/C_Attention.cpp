#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 300'000

using namespace std;

int C[MAX_N]{};

int main() {
  int N;
  string S;
  cin >> N >> S;
  int t = 0;
  for (int i = 0; i < N; ++i) {
    C[i] = t;
    if (S[i] == 'W') {
      ++t;
    }
  }
  t = 0;
  for (int i = N - 1; i >= 0; --i) {
    C[i] += t;
    if (S[i] == 'E') {
      ++t;
    }
  }
  int res = MAX_N;
  for (int i = 0; i < N; ++i) {
    res = min(res, C[i]);
  }
  printf("%d\n", res);
}