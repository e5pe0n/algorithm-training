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
    res += a - 1;
  }
  printf("%d\n", res);
}