#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

ll A, B;

int main() {
  cin >> A >> B;
  ll ans = 0;
  if (A == B) {
    printf("%lld\n", A);
    return 0;
  }
  if (A % 2 != 0) {
    ans += A;
    ++A;
  }
  int q = (B - A + 1) % 4;
  for (int i = 1; i <= q; ++i) {
    ans ^= B - q + i;
  }
  printf("%lld\n", ans);
}