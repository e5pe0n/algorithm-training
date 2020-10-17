#include <iostream>
#include <stdio.h>

#define MAX_H 3500

typedef long long ll;

using namespace std;

ll N, h, n, w;

int main() {
  cin >> N;
  for (int h = 1; h <= MAX_H; ++h) {
    for (int n = 1; n <= MAX_H; ++n) {
      ll p = N * h * n;
      ll q = 4 * h * n - N * (h + n);
      if (q > 0 && p % q == 0) {
        w = p / q;
        printf("%lld %lld %lld\n", h, n, w);
        return 0;
      }
    }
  }
}