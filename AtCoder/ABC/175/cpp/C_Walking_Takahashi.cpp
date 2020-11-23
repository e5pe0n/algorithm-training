#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, K, D;

int main() {
  cin >> X >> K >> D;
  X = abs(X);
  ll res = 0;
  if (K <= X / D) { // safe to overflow
    res = X - D * K;
  } else {
    if ((K - X / D) % 2 == 0) {
      res = abs(X - (X / D) * D);
    } else {
      res = abs(D - (X - (X / D) * D));
    }
  }
  printf("%lld\n", res);
}