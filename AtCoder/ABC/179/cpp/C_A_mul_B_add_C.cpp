#include <iostream>
#include <stdio.h>

using namespace std;

int N;

int main() {
  cin >> N;
  int res = 0;
  for (int a = 1; a < N; ++a) {
    int t = a;
    int b = 1;
    while (t * b < N) {
      ++b;
      ++res;
    }
  }
  printf("%d\n", res);
}