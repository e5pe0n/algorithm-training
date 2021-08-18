#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T;
ll L, X, Y;
ll Q;
ll E;

double vt(ll E) {
  return L * 0.5 * cos(-2 * M_PI / T * E - M_PI / 2);
}

double wt(ll E) {
  return L * 0.5 * sin(2 * M_PI / T * E - M_PI / 2) + L * 0.5;
}

int main() {
  cin >> T >> L >> X >> Y >> Q;
  ll Z = 0;
  double u = 0;
  vector<double> ress;
  while (Q--) {
    cin >> E;
    double v = vt(E);
    double w = wt(E);
    double diag =
        sqrt((u - X) * (u - X) + (v - Y) * (v - Y) + (w - Z) * (w - Z));
    double res = acos(w / diag) * 180 / M_PI;
    ress.push_back(90 - res);
  }
  for (auto res : ress)
    printf("%.8f\n", res);
}