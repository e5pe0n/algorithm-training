#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  ll X, Y;
  cin >> X >> Y;
  ll cnt = 1;
  while (X <= Y) {
    X *= 2;
    ++cnt;
  }
  printf("%lld\n", cnt - 1);
}