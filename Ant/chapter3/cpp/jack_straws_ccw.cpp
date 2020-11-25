#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 12
#define MAX_M 10000

using namespace std;

double EPS = 1e-10;

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

int N, M;
P p[MAX_N], q[MAX_N];
int a[MAX_M], b[MAX_M];
bool g[MAX_N][MAX_N];

int ccw(P p1, P p2, P q) {
  double d = (q - p1).det(p2 - p1);
  if (d > 0) { // q is at CW from line p1-p2
    return 1;
  } else if (d < 0) { // q is at CCW from line p1-p2
    return -1;
  }
  return 0; // q is on line p1-p2
}

bool on_seg(P p1, P p2, P q) {
  return min(p1.x, p2.x) <= q.x && q.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= q.y && max(p1.y, p2.y);
}

bool intersection(P p1, P p2, P p3, P p4) {
  int d1 = ccw(p3, p4, p1);
  int d2 = ccw(p3, p4, p2);
  int d3 = ccw(p1, p2, p3);
  int d4 = ccw(p1, p2, p4);
  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
    return true;
  }
  return ((d1 == 0 && on_seg(p3, p4, p1)) || (d2 == 0 && on_seg(p3, p4, p2)) ||
          (d3 == 0 && on_seg(p1, p2, p3)) || (d4 == 0 && on_seg(p1, p2, p4)));
}

void solve() {
  for (int i = 0; i < N; ++i) {
    g[i][i] = true;
    for (int j = 0; j < i; ++j) {
      g[i][j] = g[j][i] = intersection(p[i], q[i], p[j], q[j]);
    }
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] |= g[i][k] && g[k][j];
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    if (g[a[i]][b[i]]) {
      printf("CONNECTED\n");
    } else {
      printf("NOT CONNECTED\n");
    }
  }
}

int main() {
  ifstream ifs("../testset/jack_straws/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    int p1, p2;
    ifs >> p1 >> p2;
    p[i] = P(p1, p2);
  }
  for (int i = 0; i < N; ++i) {
    int q1, q2;
    ifs >> q1 >> q2;
    q[i] = P(q1, q2);
  }
  for (int i = 0; i < M; ++i) {
    ifs >> a[i] >> b[i];
    --a[i];
    --b[i];
  }
  solve();
}