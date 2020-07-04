#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int cnt = 0;
  int NA = min((int)(X / 500), A);
  int NB = min((int)(X / 100), B);
  int NC = min((int)(X / 50), C);
  for (int i = 0; i <= NA; ++i) {
    for (int j = 0; j <= NB; ++j) {
      for (int k = 0; k <= NC; ++k) {
        if (500 * i + 100 * j + 50 * k == X) {
          ++cnt;
        }
      }
    }
  }
  printf("%d\n", cnt);
}