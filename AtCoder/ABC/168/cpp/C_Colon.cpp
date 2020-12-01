#include <bits/stdc++.h>
using namespace std;

int A, B, H, M;

int main() {
  cin >> A >> B >> H >> M;
  double theta_A = 2 * M_PI * (H % 12) / 12 + 2 * M_PI * (M % 60) / (12 * 60);
  double theta_B = 2 * M_PI * (M % 60) / 60;
  double res = A * A + B * B - 2 * A * B * cos(theta_A - theta_B);
  printf("%.10f\n", sqrt(res));
}