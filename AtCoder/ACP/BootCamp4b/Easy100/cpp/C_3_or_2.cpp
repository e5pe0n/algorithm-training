#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    while (a >= 2 && a % 2 == 0) {
      a >>= 1;
      ++res;
    }
  }
  printf("%d\n", res);
}