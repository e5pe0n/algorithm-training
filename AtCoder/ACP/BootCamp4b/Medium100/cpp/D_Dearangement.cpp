#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int P[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int p;
    cin >> p;
    P[i] = p - 1;
  }
  int i = 0;
  int res = 0;
  while (i < N) {
    int cnt = 0;
    while (i < N && i == P[i]) {
      ++i;
      ++cnt;
    }
    res += (cnt + 1) / 2;
    while (i < N && i != P[i]) {
      ++i;
    }
  }
  printf("%d\n", res);
}