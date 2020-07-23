#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int res = 0;
  if (x <= y) {
    if (x < 0 && y > 0) {
      res = abs(abs(x) - y) + 1;
    } else {
      res = y - x;
    }
  } else {
    res = abs(abs(x) - abs(y)) + 1 + ((x < 0 && y < 0) || (x > 0 && y > 0));
  }
  printf("%d\n", res);
}