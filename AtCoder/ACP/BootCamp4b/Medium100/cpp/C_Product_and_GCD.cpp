#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N, P;
  cin >> N >> P;
  ll M = (ll)pow(P, 1.0 / N + 1.0e-7);
  for (ll i = M; i > 0; --i) {
    if (P % (ll)pow(i, N) == 0) {
      printf("%lld\n", i);
      return 0;
    }
  }
}