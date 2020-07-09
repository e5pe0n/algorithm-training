#include <iostream>
#include <stdio.h>

using namespace std;

int X[5];

int main() {
  int n = 0;
  int idx = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> X[i];
    int m = (10 - X[i] % 10) % 10;
    if (n < m) {
      n = m;
      idx = i;
    }
  }
  int res = 0;
  for (int i = 0; i < 5; ++i) {
    if (i != idx) {
      res += ((10 - X[i] % 10) % 10) + X[i];
    }
  }
  printf("%d\n", res + X[idx]);
}
