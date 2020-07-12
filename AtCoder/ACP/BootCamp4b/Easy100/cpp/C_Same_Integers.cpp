#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int X[3];

int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> X[i];
  }
  sort(X, X + 3);
  int ba = X[1] - X[0];
  int ca = X[2] - X[0];
  int cb = X[2] - X[1];
  if (cb % 2 == 0 && ca % 2 == 0) {
    printf("%d\n", (ca + cb) / 2);
  } else if (ba % 2 == 0) {
    printf("%d\n", 1 + (ca - 1 + cb - 1) / 2);
  } else {
    printf("%d\n", (cb + ca + 1) / 2 + 1);
  }
}