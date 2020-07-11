#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int X;
  cin >> X;
  int res = 1;
  for (int i = 2; i <= (int)sqrt(X); ++i) {
    int j = 2;
    while ((int)pow(i, j) <= X) {
      ++j;
    }
    res = max(res, (int)pow(i, j - 1));
  }
  printf("%d\n", res);
}