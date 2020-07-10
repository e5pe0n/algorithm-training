#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_B 100'000

using namespace std;

int main() {
  int N;
  cin >> N;
  int _b = MAX_B;
  int res = 0;
  for (int i = 0; i < N - 1; ++i) {
    int b;
    cin >> b;
    res += min(_b, b);
    _b = b;
  }
  printf("%d\n", res + _b);
}