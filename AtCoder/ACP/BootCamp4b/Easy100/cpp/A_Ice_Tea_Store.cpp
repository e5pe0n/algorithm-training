#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  ll res = 0;
  if (N >= 2) {
    res += min(D, min(S * 2, min(H * 4, Q * 8))) * (int)(N / 2);
    N %= 2;
  }
  if (N >= 1) {
    res += min(S, min(H * 2, Q * 4));
  }
  printf("%lld\n", res);
}