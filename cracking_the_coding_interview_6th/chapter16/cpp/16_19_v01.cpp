#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool valid_range(const ll row, const ll col, const ll height, const ll width) {
  return 0 <= row && row < height && 0 <= col && col < width;
}

ll pond_area(const vector<vector<ll>> &mat,
             ll row,
             ll col,
             vector<vector<bool>> &used) {
  queue<pll> q;
  q.push({row, col});
  used[row][col] = true;
  ll area = 1;
  while (q.size()) {
    auto [x, y] = q.front();
    q.pop();
    for (ll dx = -1; dx <= 1; ++dx) {
      for (ll dy = -1; dy <= 1; ++dy) {
        ll _x = x + dx;
        ll _y = y + dy;
        if (valid_range(_x, _y, mat.size(), mat[0].size()) && mat[_x][_y] == 0
            && !used[_x][_y]) {
          used[_x][_y] = true;
          ++area;
          q.push({_x, _y});
        }
      }
    }
  }
  return area;
}

vector<ll> pond_areas(const vector<vector<ll>> &mat) {
  vector<vector<bool>> used(mat.size(), vector<bool>(mat[0].size()));
  vector<ll> areas;
  for (ll i = 0; i < mat.size(); ++i) {
    for (ll j = 0; j < mat[0].size(); ++j) {
      if (mat[i][j] == 0 && !used[i][j]) {
        areas.push_back(pond_area(mat, i, j, used));
      }
    }
  }
  return areas;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll height, width;
  ifs >> height >> width;
  vector<vector<ll>> mat(height, vector<ll>(width));
  for (ll i = 0; i < height; ++i) {
    string line;
    ifs >> line;
    for (ll j = 0; j < width; ++j) {
      mat[i][j] = line[j] - '0';
    }
  }
  vector<ll> res = pond_areas(mat);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  solve("../testcases/16_19/01.txt");
  solve("../testcases/16_19/02.txt");
}