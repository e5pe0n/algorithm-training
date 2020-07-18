#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  if (N > M) {
    swap(N, M);
  }
  ll res = 0;
  if (M == 1) {
    res = 1;
  } else if (N == 2 || M == 2) {
    res = 0;
  } else if (N == 1) {
    res = M - 2;
  } else {
    res = (ll)(N - 2) * (M - 2);
  }
  printf("%lld\n", res);
}