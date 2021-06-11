#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Coord {
  double x, y;
  Coord() {}
  Coord(double _x, double _y) : x(_x), y(_y) {}
  friend bool operator<(Coord c1, Coord c2) {
    if (c1.x == c2.x) return c1.y < c2.y;
    return c1.x < c2.x;
  }
};

class Line {

public:
  bool infinite_slope{false};
  constexpr static double epsilon{.0001};
  double slope = 0, intercept = 0;
  Line() {}
  Line(Coord p, Coord q) {
    if (abs(p.x - q.x) > epsilon) {
      slope = (p.y - q.y) / (p.x - q.x);
      intercept = p.y - slope * p.x;
    } else {
      infinite_slope = true;
      intercept = p.x;
    }
  }
  static double floor_to_nearest_epsilon(double d) {
    ll r = (ll)(d / epsilon);
    return ((double)r) * epsilon;
  }
  static bool is_equivalent(double a, double b) {
    return abs(a - b) < epsilon;
  }
  friend bool operator==(Line line1, Line line2) {
    return is_equivalent(line1.slope, line2.slope)
           && is_equivalent(line1.intercept, line2.intercept)
           && line1.infinite_slope == line2.infinite_slope;
  }
  string repr() {
    if (infinite_slope) {
      return "1.0x + 0.0y + " + to_string(-intercept) + " = 0";
    }
    return to_string(-slope) + "x + 1.0y + " + to_string(-intercept) + " = 0";
  }
};

ll cnt_equivalent_lines(const vector<Line> &lines, Line &line) {
  ll cnt = 0;
  for (auto parallel_line : lines) {
    if (parallel_line == line) ++cnt;
  }
  return cnt;
}

ll cnt_equivalent_lines(map<double, vector<Line>> lines_by_slope, Line &line) {
  double key = Line::floor_to_nearest_epsilon(line.slope);
  ll cnt = cnt_equivalent_lines(lines_by_slope[key], line);
  cnt += cnt_equivalent_lines(lines_by_slope[key - Line::epsilon], line);
  cnt += cnt_equivalent_lines(lines_by_slope[key + Line::epsilon], line);
  return cnt;
}

Line get_best_line(map<double, vector<Line>> lines_by_slope) {
  Line best_line(Coord{0, 0}, Coord{0, 0});
  ll best_cnt = 0;
  for (auto [slope, lines] : lines_by_slope) {
    for (auto line : lines) {
      ll cnt = cnt_equivalent_lines(lines_by_slope, line);
      if (cnt > best_cnt) {
        best_line = line;
        best_cnt = cnt;
      }
    }
  }
  return best_line;
}

map<double, vector<Line>> get_list_of_lines(const vector<Coord> &coords) {
  map<double, vector<Line>> lines_by_slope;
  for (ll i = 0; i < coords.size() - 1; ++i) {
    for (ll j = i + 1; j < coords.size(); ++j) {
      Line line(coords[i], coords[j]);
      double key = Line::floor_to_nearest_epsilon(line.slope);
      lines_by_slope[key].push_back(line);
    }
  }
  return lines_by_slope;
}

Line find_best_line(const vector<Coord> &coords) {
  map<double, vector<Line>> lines_by_slope = get_list_of_lines(coords);
  return get_best_line(lines_by_slope);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<Coord> coords(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> coords[i].x >> coords[i].y;
  }
  sort(coords.begin(), coords.end());
  Line res = find_best_line(coords);
  puts(res.repr().c_str());
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
// 1.000000x + 1.0y + 4.000000 = 0

// # ../testcases/16_14/02.txt
// -0.200000x + 1.0y + -0.400000 = 0

// # ../testcases/16_14/03.txt
// 0.000000x + 1.0y + -0.000000 = 0

// # ../testcases/16_14/04.txt
// 1.0x + 0.0y + -0.000000 = 0

// # ../testcases/16_14/05.txt
// 1.0x + 0.0y + -0.000000 = 0