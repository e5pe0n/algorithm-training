#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int res = 0;
  if (X == Y) {
    res = min(A + B, 2 * C) * X;
  } else if (X < Y) {
    res = min(A + B, 2 * C) * X + min(B, 2 * C) * (Y - X);
  } else {
    res = min(A + B, 2 * C) * Y + min(A, 2 * C) * (X - Y);
  }
  printf("%d\n", res);
}