#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll L, X, Y, S, D;

int main() {
  cin >> L >> X >> Y >> S >> D;
  ll d_cw = (D - S + L) % L;
  ll d_ccw = (S - D + L) % L;
  double t_cw = (double)d_cw / (Y + X);
  double t_ccw = Y - X == 0 ? -1 : (double)d_ccw / (Y - X);
  double res = min(t_cw, t_ccw);
  if (t_cw < 0.0) res = t_ccw;
  if (t_ccw < 0.0) res = t_cw;
  printf("%.7f\n", res);
}