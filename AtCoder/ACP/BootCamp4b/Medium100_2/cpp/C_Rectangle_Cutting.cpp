#include <bits/stdc++.h>
using namespace std;

double W, H, x, y;

void solve() {
  double res = H * W / 2.0;
  printf("%.10f %d\n", res, W / 2 == x && H / 2 == y);
}

int main() {
  cin >> W >> H >> x >> y;
  solve();
}