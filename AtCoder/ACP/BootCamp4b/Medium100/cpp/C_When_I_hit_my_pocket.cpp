#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll K, A, B;
  cin >> K >> A >> B;
  ll res = 0;
  if (A >= B - 2 || A + 1 > K) {
    res = K + 1;
  } else {
    K -= A + 1;
    ll t = K / 2;
    res = (t + 1) * B - t * A + K % 2;
  }
  printf("%lld\n", res);
}