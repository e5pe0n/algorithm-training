#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N, X;
  cin >> N >> X;
  ll m = X;
  for (int i = 1; i < 5; ++i) {
    cin >> X;
    m = min(m, X);
  }
  printf("%lld\n", (ll)ceil((double)N / m) + 4);
}