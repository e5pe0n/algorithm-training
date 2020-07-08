#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int NA = min(X / 500, A);
  int NB = min(X / 100, B);
  int NC = min(X / 50, C);
  int cnt = 0;
  for (int i = 0; i <= NA; ++i) {
    for (int j = 0; j <= NB; ++j) {
      for (int k = 0; k <= NC; ++k) {
        cnt += 500 * i + 100 * j + 50 * k == X;
      }
    }
  }
  printf("%d\n", cnt);
}