#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

typedef long long ll;

using namespace std;

int X[MAX_N];
int _X[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
    _X[i] = X[i];
  }
  sort(_X, _X + N);
  int m = N / 2;
  for (int i = 0; i < N; ++i) {
    if (X[i] >= _X[m]) {
      printf("%d\n", _X[m - 1]);
    } else {
      printf("%d\n", _X[m]);
    }
  }
}