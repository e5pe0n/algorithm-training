#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int T[MAX_N];

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }
  sort(T, T + N);
  int i = 0;
  int res = 0;
  while (i < N) {
    int j = 0;
    while (i < N && j < C && T[i] - T[i - j] <= K) {
      ++i;
      ++j;
    }
    ++res;
  }
  printf("%d\n", res);
}