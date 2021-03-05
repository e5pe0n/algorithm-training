#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

int main() {
  cin >> N >> M;
  double S = N * 2 * M_PI / 12 + M * 2 * M_PI / 60 / 12;
  double L = M * 2 * M_PI / 60;
  double c = cos(S) * cos(L) + sin(S) * sin(L);
  double d = acos(c) * 360 / (2 * M_PI);
  if (d < 0) d += 360;
  printf("%.5f\n", min(d, 360 - d));
}