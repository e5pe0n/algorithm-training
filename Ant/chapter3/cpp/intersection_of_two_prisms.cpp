#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <vector>

#define INF 1'000'000'000
#define MAX_M 100
#define MAX_N 100

using namespace std;

int M, N;
int X1[MAX_M], Y1[MAX_M];
int X2[MAX_N], Z2[MAX_N];

double width(int *X, int *Y, int n, double x) {
  double lb = INF;
  double ub = -INF;
  for (int i = 0; i < n; ++i) {
    double x1 = X[i];
    double y1 = Y[i];
    double x2 = X[(i + 1) % n];
    double y2 = Y[(i + 1) % n];
    if ((x1 - x) * (x2 - x) <= 0 && x1 != x2) {
      double y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
      lb = min(lb, y);
      ub = max(ub, y);
    }
  }
  return max(0.0, ub - lb);
}

void solve() {
  int min1 = *min_element(X1, X1 + M);
  int max1 = *max_element(X1, X1 + M);
  int min2 = *min_element(X2, X2 + N);
  int max2 = *max_element(X2, X2 + N);
  vector<int> xs;
  for (int i = 0; i < M; ++i) {
    xs.push_back(X1[i]);
  }
  for (int i = 0; i < N; ++i) {
    xs.push_back(X2[i]);
  }
  sort(xs.begin(), xs.end());

  double res = 0;
  for (int i = 0; i + 1 < xs.size(); ++i) {
    double a = xs[i];
    double b = xs[i + 1];
    double c = (a + b) / 2;
    if (min1 <= c && c <= max1 && min2 <= c && c <= max2) {
      // Simpson's rule : S(f(x)dx)(a..b) ~ (b - a) / 6 (f(a) + 4f((a + b) / 2) + f(b))
      double fa = width(X1, Y1, M, a) * width(X2, Z2, N, a);
      double fb = width(X1, Y1, M, b) * width(X2, Z2, N, b);
      double fc = width(X1, Y1, M, c) * width(X2, Z2, N, c);
      res += (b - a) / 6 * (fa + 4 * fc + fb);
    }
  }
  printf("%.10f\n", res);
}

int main() {
  ifstream ifs("../testset/intersection_of_two_prisms/test1.txt");
  ifs >> M >> N;
  for (int i = 0; i < M; ++i) {
    ifs >> X1[i] >> Y1[i];
  }
  for (int i = 0; i < N; ++i) {
    ifs >> X2[i] >> Z2[i];
  }
  solve();
}