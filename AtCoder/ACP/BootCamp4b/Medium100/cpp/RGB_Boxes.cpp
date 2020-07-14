#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int X[3];

int main() {
  int N;
  for (int i = 0; i < 3; ++i) {
    cin >> X[i];
  }
  cin >> N;
  sort(X, X + 3);
  ll cnt = 0;
  int N2 = (int)(N / X[2]);
  int N1 = (int)(N / X[1]);
  for (int i = 0; i <= N2; ++i) {
    for (int j = 0; j <= N1; ++j) {
      if (X[2] * i + X[1] * j + X[0] * max(0, (N - X[2] * i - X[1] * j) / X[0]) == N) {
        ++cnt;
      }
    }
  }
  printf("%lld\n", cnt);
}