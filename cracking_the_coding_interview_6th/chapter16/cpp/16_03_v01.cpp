#include <fstream>
#include <string>
using namespace std;
using ll = long long;

struct Coord {
  ll x, y;
};

struct Vector {
  Coord from, to;
};

ll cross_product(Vector v1, Vector v2) {
  ll x1 = v1.to.x - v1.from.x;
  ll y1 = v1.to.y - v1.from.y;
  ll x2 = v2.to.x - v2.from.x;
  ll y2 = v2.to.y - v2.from.y;
  return x1 * y2 - x2 * y1;
}

ll direction(Vector v1, Coord p) {
  Vector v2{v1.from, p};
  return cross_product(v1, v2);
}

bool on_segment(Vector v1, Coord p) {
  ll xl = min(v1.from.x, v1.to.x);
  ll xr = max(v1.from.x, v1.to.x);
  ll yl = min(v1.from.y, v1.to.y);
  ll yr = max(v1.from.y, v1.to.y);
  return xl <= p.x && p.x <= xr && yl <= p.y && p.y <= yr;
}

bool intersect(Vector v1, Vector v2) {
  ll d1 = direction(v1, v2.from);
  ll d2 = direction(v1, v2.to);
  ll d3 = direction(v2, v1.from);
  ll d4 = direction(v2, v1.to);
  if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0))
      && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0)))
    return true;
  if (d1 == 0 && on_segment(v1, v2.from) || (d2 == 0 && on_segment(v1, v2.to))
      || (d3 == 0 && on_segment(v2, v1.from))
      || (d4 == 0 && on_segment(v2, v1.to)))
    return true;
  return false;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll x0, x1, y0, y1;
  ifs >> x0 >> y0 >> x1 >> y1;
  Vector v1{Coord{x0, y0}, Coord{x1, y1}};
  ifs >> x0 >> y0 >> x1 >> y1;
  Vector v2{Coord{x0, y0}, Coord{x1, y1}};
  puts(intersect(v1, v2) ? "yes" : "no");
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