#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  double t = 1'000'000;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int h;
    cin >> h;
    double _t = abs(A - (T - h * 0.006));
    if (_t < t) {
      res = i;
      t = _t;
    }
  }
  printf("%d\n", res + 1);
}