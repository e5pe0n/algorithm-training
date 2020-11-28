#include <algorithm>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_N 50000

using namespace std;

const double EPS = 1e-10;

double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b))) {
    return 0;
  }
  return a + b;
}

struct P {
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(P p) { return P(add(x, p.x), add(y, p.y)); }
  P operator-(P p) { return P(add(x, -p.x), add(y, -p.y)); }
  P operator*(double d) { return P(x * d, y * d); }
  double dot(P p) { return add(x * p.x, y * p.y); }
  double det(P p) { return add(x * p.y, -y * p.x); }
};

int N;
P ps[MAX_N];

bool cmp_x(const P &p1, const P &p2) {
  if (p1.x == p2.x) {
    return p1.y < p2.y;
  }
  return p1.x < p2.x;
}

vector<P> convex_hull(P *ps, int n) {
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);

  // make lower convex hull
  for (int i = 0; i < n; ++i) {
    while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) {
      --k;
    }
    qs[k++] = ps[i]; // k is the next insertion point
  }
  // make upper convex hull
  for (int i = n - 2, t = k; i >= 0; --i) { // exclude i = n - 1 because the point must be in convex hull
    while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) {
      --k;
    }
    qs[k++] = ps[i];
  }
  qs.resize(k - 1); // exclude i = k because it duplicate of i = 0
  return qs;
}

// square of distance
double dist(P p1, P p2) { return (p1 - p2).dot(p1 - p2); }

void solve() {
  vector<P> qs = convex_hull(ps, N);
  double res = 0;
  for (int i = 0; i < qs.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      res = max(res, dist(qs[i], qs[j]));
    }
  }
  printf("%.0f\n", res);
}

int main() {
  ifstream ifs("../testset/beauty_contest/test1.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    double x, y;
    ifs >> x >> y;
    ps[i] = P(x, y);
  }
  solve();
}