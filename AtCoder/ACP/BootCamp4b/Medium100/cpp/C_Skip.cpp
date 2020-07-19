#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int Y[MAX_N];

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int N, X;
  cin >> N >> X;
  for (int i = 0; i < N; ++i) {
    cin >> Y[i];
  }
  sort(Y, Y + N);
  int res = abs(X - Y[0]);
  for (int i = 0; i < N - 1; ++i) {
    res = gcd(res, Y[i + 1] - Y[i]);
  }
  printf("%d\n", res);
}