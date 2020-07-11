#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;
  ll res = N;
  for (ll i = 1; i <= (ll)(sqrt(N)); ++i) {
    ll j = (ll)(N / i);
    if (j * i == N) {
      res = min(res, j - 1 + i - 1);
    }
  }
  printf("%lld\n", res);
}