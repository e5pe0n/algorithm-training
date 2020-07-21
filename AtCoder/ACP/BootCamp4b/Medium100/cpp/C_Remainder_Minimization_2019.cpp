#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define INF 2'000'000'001

using namespace std;

int main() {
  int L, R;
  cin >> L >> R;
  if (ceil((double)L / 2019) <= (R / 2019)) {
    printf("0\n");
  } else {
    int res = INF;
    for (int i = L % 2019; i < R % 2019; ++i) {
      for (int j = L % 2019 + 1; j < R % 2019 + 1; ++j) {
        res = min(res, (i * j) % 2019);
      }
    }
    printf("%d\n", res);
  }
}