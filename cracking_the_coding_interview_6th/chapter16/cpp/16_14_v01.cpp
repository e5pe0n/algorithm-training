#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Coord {
  double x, y;

  bool operator<(const Coord &other) {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
};

struct Line {
  // ax + by + c = 0
  double a, b, c;
};

Line get_line(double dx1, double dy1, double x, double y) {
  if (dx1 == 0) return Line{1, 0, -x};
  // y = px + q
  double p = dy1 / dx1;
  double q = y - p * x;
  return Line{-p, 1, -q}; // -px + 1y + -q = 0
}

Line most_passing_line(vector<Coord> v) {
  if (v.size() == 1) return Line{1, 0, -v[0].x};
  sort(v.begin(), v.end());
  ll max_cnt = 0;
  Line res;
  for (ll i = 0; i < v.size() - 1; ++i) {
    for (ll j = i + 1; j < v.size(); ++j) {
      double dx1 = v[i].x - v[j].x;
      double dy1 = v[i].y - v[j].y;
      ll cnt = 2;
      for (ll k = j + 1; k < v.size(); ++k) {
        double dx2 = v[i].x - v[k].x;
        double dy2 = v[i].y - v[k].y;
        if (dx1 * dy2 == dx2 * dy1) ++cnt;
      }
      if (max_cnt < cnt) {
        max_cnt = cnt;
        res = get_line(dx1, dy1, v[i].x, v[i].y);
      }
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<Coord> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i].x >> v[i].y;
  }
  Line res = most_passing_line(v);
  printf("%fx + %fy + %f = 0\n", res.a, res.b, res.c);
  puts("");
}

int main() {
  solve("../testcases/16_14/01.txt");
  solve("../testcases/16_14/02.txt");
  solve("../testcases/16_14/03.txt");
  solve("../testcases/16_14/04.txt");
  solve("../testcases/16_14/05.txt");
}

// # ../testcases/16_14/01.txt
// 1.000000x + 1.000000y + 4.000000 = 0

// # ../testcases/16_14/02.txt
// -0.200000x + 1.000000y + -0.400000 = 0

// # ../testcases/16_14/03.txt
// 0.000000x + 1.000000y + -0.000000 = 0

// # ../testcases/16_14/04.txt
// 1.000000x + 0.000000y + -0.000000 = 0

// # ../testcases/16_14/05.txt
// 1.000000x + 0.000000y + -0.000000 = 0
