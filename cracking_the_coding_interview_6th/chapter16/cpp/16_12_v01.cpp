#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

struct Coord {
  double x, y;
};

struct Line {
  // ax + by + c = 0
  double a, b, c;
};

Line half_line(Coord topleft1,
               Coord btmright1,
               Coord topleft2,
               Coord btmright2) {
  Coord center1{(topleft1.x + btmright1.x) / 2, (topleft1.y + btmright1.y) / 2};
  Coord center2{(topleft2.x + btmright2.x) / 2, (topleft2.y + btmright2.y) / 2};
  double dx = center1.x - center2.x;
  double dy = center1.y - center2.y;
  if (dx == 0) return Line{1, 0, -center1.x};
  // y = px + q
  double p = dy / dx;
  double q = center1.y - p * center1.x;
  return Line{-p, 1, -q}; // -px + 1y - q = 0
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  Coord topleft1, btmright1, topleft2, btmright2;
  ifs >> topleft1.x >> topleft1.y >> btmright1.x >> btmright1.y;
  ifs >> topleft2.x >> topleft2.y >> btmright2.x >> btmright2.y;
  Line line = half_line(topleft1, btmright1, topleft2, btmright2);
  printf("%fx + %fy + %f = 0\n", line.a, line.b, line.c);
  puts("");
}

int main() {
  solve("../testcases/16_12/01.txt");
  solve("../testcases/16_12/02.txt");
  solve("../testcases/16_12/03.txt");
  solve("../testcases/16_12/04.txt");
  solve("../testcases/16_12/05.txt");
  solve("../testcases/16_12/06.txt");
}

// # ../testcases/16_12/01.txt
// -0.500000x + 1.000000y + -4.500000 = 0

// # ../testcases/16_12/02.txt
// -1.400000x + 1.000000y + 14.400000 = 0

// # ../testcases/16_12/03.txt
// 1.750000x + 1.000000y + 11.250000 = 0

// # ../testcases/16_12/04.txt
// 0.000000x + 1.000000y + -1.000000 = 0

// # ../testcases/16_12/05.txt
// 1.000000x + 0.000000y + -1.000000 = 0

// # ../testcases/16_12/06.txt
// 1.000000x + 0.000000y + -0.000000 = 0