#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int res = 0;
  int _t;
  cin >> _t;
  for (int i = 1; i < N; ++i) {
    int t;
    cin >> t;
    res += min(T, t - _t);
    _t = t;
  }
  printf("%d\n", res + T);
}