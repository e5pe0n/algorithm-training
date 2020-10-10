#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int ans = 0;
  int p = M / N;
  for (p; p > 0; --p) {
    int q = M % p;
    if (q % p == 0) {
      ans = p;
      break;
    }
  }
  printf("%d\n", ans);
}