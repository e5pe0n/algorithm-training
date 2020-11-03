#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 10000
#define INF 1e18

using namespace std;

int n, k;
int w[MAX_N], v[MAX_N];
double y[MAX_N];

bool C(double x) {
  for (int i = 0; i < n; ++i) {
    y[i] = v[i] - x * w[i];
  }
  sort(y, y + n);
  double t = 0;
  for (int i = 0; i < k; ++i) {
    t += y[n - 1 - i];
  }
  return t >= 0;
}

int main() {
  ifstream ifs("../testset/mean_maximization/test1.txt");
  ifs >> n >> k;
  for (int i = 0; i < n; ++i) {
    ifs >> w[i] >> v[i];
  }
  double lb = 0;
  double ub = INF;
  for (int i = 0; i < 100; ++i) {
    double mid = (lb + ub) / 2;
    if (C(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%.2f\n", lb);
}