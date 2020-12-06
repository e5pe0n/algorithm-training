#include <bits/stdc++.h>
using namespace std;

double L;

void solve() {
  double res = (L / 3) * (L / 3) * (L / 3);
  printf("%.7f\n", res);
}

int main() {
  cin >> L;
  solve();
}