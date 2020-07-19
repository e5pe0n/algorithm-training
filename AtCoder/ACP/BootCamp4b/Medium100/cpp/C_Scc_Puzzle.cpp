#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll N, M;
  cin >> N >> M;
  ll res = 0;
  if (2 * N <= M) {
    res = N + (ll)(M - 2 * N) / 4;
  } else {
    res = M / 2;
  }
  printf("%lld\n", res);
}