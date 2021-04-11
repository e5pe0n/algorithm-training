#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll R, X, Y;

int main() {
  cin >> R >> X >> Y;
  double dst = sqrt(X * X + Y * Y);
  ll res = (ll)ceil(dst / R) + (dst < R);
  printf("%lld\n", res);
}