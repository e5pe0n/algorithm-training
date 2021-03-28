#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, X0, Y0, X2, Y2;

int main() {
  cin >> N >> X0 >> Y0 >> X2 >> Y2;
  double Cx = (X0 + X2) / 2.0, Cy = (Y0 + Y2) / 2.0;
  double theta = 2 * M_PI / N;
  double X1 = (X0 - Cx) * cos(theta) - (Y0 - Cy) * sin(theta) + Cx;
  double Y1 = (X0 - Cx) * sin(theta) + (Y0 - Cy) * cos(theta) + Cy;
  printf("%.6f %.6f\n", X1, Y1);
}