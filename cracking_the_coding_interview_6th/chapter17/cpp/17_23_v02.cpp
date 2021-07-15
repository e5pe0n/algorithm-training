#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ppll = pair<pll, pll>;

struct CntBlack {
  ll left = 0, right = 0, above = 0, below = 0;
  string repr() {
    return "left=" + to_string(left) + ", right=" + to_string(right)
           + ", above=" + to_string(above) + ", below=" + to_string(below);
  }
};

vector<vector<CntBlack>> cnt_black(const vector<string> &arr) {
  vector<vector<CntBlack>> blacks(arr.size(), vector<CntBlack>(arr.size()));
  for (ll i = 0; i < arr.size(); ++i) {
    for (ll j = 1; j < arr.size(); ++j) {
      if (arr[i][j - 1] == 'x') {
        blacks[i][j].left = blacks[i][j - 1].left + 1;
      } else {
        blacks[i][j].left = 0;
      }
    }
    for (ll j = arr.size() - 2; j >= 0; --j) {
      if (arr[i][j + 1] == 'x') {
        blacks[i][j].right = blacks[i][j + 1].right + 1;
      } else {
        blacks[i][j].right = 0;
      }
    }
  }
  for (ll j = 0; j < arr.size(); ++j) {
    for (ll i = 1; i < arr.size(); ++i) {
      if (arr[i - 1][j] == 'x') {
        blacks[i][j].above = blacks[i - 1][j].above + 1;
      } else {
        blacks[i][j].above = 0;
      }
    }
    for (ll i = arr.size() - 2; i >= 0; --i) {
      if (arr[i + 1][j] == 'x') {
        blacks[i][j].below = blacks[i + 1][j].below + 1;
      } else {
        blacks[i][j].below = 0;
      }
    }
  }
  return blacks;
}

ppll find_max_subsquare(const vector<string> &arr) {
  vector<vector<CntBlack>> blacks = cnt_black(arr);
  ll max_delta = 0;
  ppll res = {{-1, -1}, {-1, -1}};
  for (ll i = 0; i < arr.size(); ++i) {
    for (ll j = 0; j < arr.size(); ++j) {
      if (arr[i][j] != 'x' || blacks[i][j].right != blacks[i][j].below)
        continue;
      ll delta = blacks[i][j].below;
      if (delta <= max_delta) continue;
      pll topright = {i, j + delta};
      pll btmleft = {i + delta, j};
      pll btmright = {i + delta, j + delta};
      if (!(blacks[topright.first][topright.second].left == delta
            && blacks[topright.first][topright.second].below == delta
            && blacks[btmleft.first][btmleft.second].above == delta
            && blacks[btmleft.first][btmleft.second].right == delta
            && blacks[btmright.first][btmright.second].left == delta
            && blacks[btmright.first][btmright.second].above == delta))
        continue;
      bool exist_outer_black = false;
      for (ll d = 0; d <= delta; ++d) {
        if (blacks[i][j + d].above > 0 || blacks[i + d][j].left > 0
            || blacks[topright.first + d][topright.second].right > 0
            || blacks[btmleft.first][btmleft.second + d].below > 0) {
          exist_outer_black = true;
          break;
        }
      }
      if (exist_outer_black) continue;
      max_delta = delta;
      res = {{i, j}, btmright};
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<string> arr(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> arr[i];
  }
  ppll res = find_max_subsquare(arr);
  printf("(%lld, %lld), (%lld, %lld)\n",
         res.first.first,
         res.first.second,
         res.second.first,
         res.second.second);
  puts("");
}

int main() {
  solve("../testcases/17_23/01.txt");
  solve("../testcases/17_23/02.txt");
  solve("../testcases/17_23/03.txt");
  solve("../testcases/17_23/04.txt");
  solve("../testcases/17_23/05.txt");
  solve("../testcases/17_23/06.txt");
}

// # ../testcases/17_23/01.txt
// (1, 1), (5, 5)

// # ../testcases/17_23/02.txt
// (0, 0), (9, 9)

// # ../testcases/17_23/03.txt
// (5, 6), (8, 9)

// # ../testcases/17_23/04.txt
// (0, 0), (9, 9)

// # ../testcases/17_23/05.txt
// (7, 6), (9, 8)

// # ../testcases/17_23/06.txt
// (8, 0), (9, 1)