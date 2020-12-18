#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double A, B, X;

void solve() {
  double V = A * A * B / 2;
  double res;
  if (X == V * 2) {
    res = 90;
  } else if (X <= V) {
    res = atan(2.0 * X / (A * B * B)) * 180 / M_PI;
  } else {
    res = 90 - atan((2.0 * A * A * B - 2 * X) / (A * A * A)) * 180 / M_PI;
  }
  printf("%.7f\n", 90 - res);
}

int main() {
  cin >> A >> B >> X;
  solve();
}