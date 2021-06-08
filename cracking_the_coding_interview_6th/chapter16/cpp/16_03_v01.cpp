#include <fstream>
#include <string>
using namespace std;
using ll = long long;

struct Coord {
  double x, y;
};

struct Vector {
  Coord from, to;
};

struct Res {
  bool exists_intersection;
  Coord intersection;
};

double cross_product(Vector v1, Vector v2) {
  double x1 = v1.to.x - v1.from.x;
  double y1 = v1.to.y - v1.from.y;
  double x2 = v2.to.x - v2.from.x;
  double y2 = v2.to.y - v2.from.y;
  return x1 * y2 - x2 * y1;
}

ll direction(Vector v1, Coord p) {
  Vector v2{v1.from, p};
  return cross_product(v1, v2);
}

bool on_segment(Vector v1, Coord p) {
  double xl = min(v1.from.x, v1.to.x);
  double xr = max(v1.from.x, v1.to.x);
  double yl = min(v1.from.y, v1.to.y);
  double yr = max(v1.from.y, v1.to.y);
  return xl <= p.x && p.x <= xr && yl <= p.y && p.y <= yr;
}

Coord _intersection(Vector v1, Vector v2) {
  double dx1 = v1.from.x - v1.to.x;
  double dx2 = v2.from.x - v2.to.x;
  if (dx1 == 0) {
    swap(dx1, dx2);
    swap(v1, v2);
  }
  double dy1 = v1.from.y - v1.to.y;
  double dy2 = v2.from.y - v2.to.y;
  double a1 = dy1 / dx1;
  double b1 = v1.from.y - a1 * v1.from.x;
  if (dx2 == 0) return Coord{v2.from.x, a1 * v2.from.x + b1};
  double a2 = dy2 / dx2;
  double b2 = v2.from.y - a2 * v2.from.x;
  double x = (b2 - b1) / (a1 - a2);
  return Coord{x, a1 * x + b1};
}

Res intersection(Vector v1, Vector v2) {
  double d1 = direction(v1, v2.from);
  double d2 = direction(v1, v2.to);
  double d3 = direction(v2, v1.from);
  double d4 = direction(v2, v1.to);
  if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0))
      && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) {
    return Res{true, _intersection(v1, v2)};
  }
  if (d1 == 0 && on_segment(v1, v2.from)) return Res{true, v2.from};
  if (d2 == 0 && on_segment(v1, v2.to)) return Res{true, v2.to};
  if (d3 == 0 && on_segment(v2, v1.from)) return Res{true, v1.from};
  if (d4 == 0 && on_segment(v2, v1.to)) return Res{true, v1.to};
  return Res{false};
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  double x0, x1, y0, y1;
  ifs >> x0 >> y0 >> x1 >> y1;
  Vector v1{Coord{x0, y0}, Coord{x1, y1}};
  ifs >> x0 >> y0 >> x1 >> y1;
  Vector v2{Coord{x0, y0}, Coord{x1, y1}};
  puts(intersection(v1, v2) ? "yes" : "no");
  puts("");
}

int main() {
  solve("../testcases/16_03/01.txt");
  solve("../testcases/16_03/02.txt");
  solve("../testcases/16_03/03.txt");
  solve("../testcases/16_03/04.txt");
  solve("../testcases/16_03/05.txt");
  solve("../testcases/16_03/06.txt");
}

// # ../testcases/16_03/01.txt
// yes

// # ../testcases/16_03/02.txt
// yes

// # ../testcases/16_03/03.txt
// yes

// # ../testcases/16_03/04.txt
// yes

// # ../testcases/16_03/05.txt
// no

// # ../testcases/16_03/06.txt
// yes