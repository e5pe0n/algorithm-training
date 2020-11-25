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

bool on_seg(P p1, P p2, P q) { return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0; }

P intersection(P p1, P p2, P q1, P q2) {
  return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

int N, M;
P p[MAX_N], q[MAX_N];
int a[MAX_M], b[MAX_M];
bool g[MAX_N][MAX_N];

void solve() {
  for (int i = 0; i < N; ++i) {
    g[i][i] = true;
    for (int j = 0; j < i; ++j) {
      if ((p[i] - q[i]).det(p[j] - q[j]) == 0) {
        // parallel
        g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j]) || on_seg(p[i], q[i], q[j]) ||
                            on_seg(p[j], q[j], p[i]) || on_seg(p[j], q[j], q[i]);
      } else {
        // not parallel
        P r = intersection(p[i], q[i], p[j], q[j]);
        g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
      }
    }
  }
  // Warshall-Floyd algorithm
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] |= g[i][k] && g[k][j];
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    printf("%s\n", g[a[i]][b[i]] ? "CONNECTED" : "NOT CONNECTED");
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