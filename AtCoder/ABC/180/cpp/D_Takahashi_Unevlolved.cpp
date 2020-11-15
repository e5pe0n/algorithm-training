#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll X, Y, A, B;

int main() {
  cin >> X >> Y >> A >> B;
  ll res = 0;
  while ((double)X * A <= 1e18 && X * A <= X + B && A * X < Y) {
    X *= A;
    ++res;
  }
  res += (Y - 1 - X) / B;
  printf("%lld\n", res);
}