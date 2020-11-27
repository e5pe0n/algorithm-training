#include <algorithm>
#include <fstream>
#include <math.h>
#include <stdio.h>

#define MAX_N 50

using namespace std;

const double EPS = 1e-10;
const double g = 9.8;

int N, V, X, Y;
int L[MAX_N], B[MAX_N], R[MAX_N], T[MAX_N];

double calc(double vy, double t) { return vy * t - g * t * t / 2; }

int cmp(double lb, double ub, double a) {
  // a == 0  => abs(a) < EPS i.e. -EPS < a < EPS
  // a < 0   => a < -EPS
  // a <= 0  => a < EPS

  // a <= lb => a < lb + EPS
  // ub <= a => ub - EPS < a
  return a < lb + EPS ? -1 : a > ub - EPS ? 1 : 0;
}

// launch a bird to pass through (qx, qy)
bool check(double qx, double qy) {
  // solve a simultaneous equation:
  // vx^2 + vy^ 2 = V^2
  // vx t = qx
  // vy t - 1/2 g t^2
  double a = g * g / 4;
  double b = g * qy - V * V;
  double c = qx * qx + qy * qy;

  double D = b * b - 4 * a * c;
  if (D < 0 && D > -EPS) {
    D = 0;
  }
  if (D < 0) {
    return false;
  }
  for (int d = -1; d <= 1; d += 2) {
    double t2 = (-b + d * sqrt(D)) / (2 * a);
    if (t2 <= 0) {
      continue;
    }
    double t = sqrt(t2);
    double vx = qx / t;
    double vy = (qy + g * t * t / 2) / t;

    // yt is height when a bird reach X
    double yt = calc(vy, X / vx);
    if (yt < Y - EPS) {
      continue;
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      if (L[i] >= X) {
        continue;
      }
      if (R[i] == X && Y <= T[i] && B[i] <= yt) {
        ok = false;
      }
      int yL = cmp(B[i], T[i], calc(vy, L[i] / vx));
      int yR = cmp(B[i], T[i], calc(vy, R[i] / vx));
      int xH = cmp(L[i], R[i], vx * (vy / g));    // x at the heighest point
      int yH = cmp(B[i], T[i], calc(vy, vy / g)); // y at the heighest point
      if (xH == 0 && yH >= 0 && yL <= 0) {
        ok = false;
      }
      if (yL * yR <= 0) {
        ok = false;
      }
    }
    if (ok) {
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < N; ++i) {
    R[i] = min(R[i], X);
  }
  bool ok = check(X, Y);
  for (int i = 0; i < N; ++i) {
    ok |= check(L[i], T[i]);
    ok |= check(R[i], T[i]);
  }
  puts(ok ? "Yes" : "No");
}

int main() {
  ifstream ifs("../testset/white_bird/test4.txt");
  ifs >> N >> V >> X >> Y;
  for (int i = 0; i < N; ++i) {
    ifs >> L[i] >> B[i] >> R[i] >> T[i];
  }
  solve();
}