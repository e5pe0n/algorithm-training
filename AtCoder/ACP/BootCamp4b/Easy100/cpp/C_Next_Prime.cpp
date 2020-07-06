#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int X;
  cin >> X;
  if (X == 2) {
    printf("2\n");
    return 0;
  }
  if (X % 2 == 0) {
    ++X;
  }
  for (int i = X;; i += 2) {
    double s = sqrt(i);
    bool flg = true;
    for (int j = 3; j <= s; j += 2) {
      if (i % j == 0) {
        flg = false;
        break;
      }
    }
    if (flg) {
      printf("%d\n", i);
      return 0;
    }
  }
}