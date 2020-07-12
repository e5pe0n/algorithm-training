#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int V[3];

int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> V[i];
  }
  sort(V, V + 3);
  ll L = (ll)(V[2] / 2);
  printf("%lld\n", V[0] * V[1] * (V[2] - L - L));
}