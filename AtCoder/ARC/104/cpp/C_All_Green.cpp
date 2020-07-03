#include <algorithm>
#include <bitset>
#include <iostream>
#include <stdio.h>

#define MAX_D 10

using namespace std;

int P[MAX_D]{};
int C[MAX_D]{};

int main() {
  int D, G;
  cin >> D >> G;
  for (int i = 0; i < D; ++i) {
    cin >> P[i] >> C[i];
  }

  int res = 1000;
  for (int i = 0; i < (1 << D); ++i) {
    bitset<1000> b(i);
    int s = 0;
    int cnt = 0;
    int k = 0;
    for (int j = 0; j < D; ++j) {
      if (b.test(j)) {
        s += 100 * (j + 1) * P[j] + C[j];
        cnt += P[j];
      } else {
        k = j;
      }
    }
    if (s >= G) {
      res = min(res, cnt);
    } else {
      for (int l = 0; l < P[k] - 1; ++l) {
        s += 100 * (k + 1);
        ++cnt;
        if (s >= G) {
          res = min(res, cnt);
          break;
        }
      }
    }
  }
  printf("%d\n", res);
}