#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;
  ll n = (ll)ceil((-1 + sqrt(1 + 8 * N)) / 2);
  ll d = n * (n + 1) / 2 - N;
  for (int i = 1; i <= n; ++i) {
    if (i != d) {
      printf("%d\n", i);
    }
  }
}
