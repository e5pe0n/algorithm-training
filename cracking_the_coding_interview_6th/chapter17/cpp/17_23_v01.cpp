#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ppll = pair<pll, pll>;

bool valid_coord(const ll i, const ll j, const ll end) {
  return 0 <= i && i < end && 0 <= j && j < end;
}

ll check_subsquare(ll r,
                   ll c,
                   const vector<string> &arr,
                   vector<vector<bool>> &used) {
  ll _c = c;
  ll n = arr.size();
  if (valid_coord(r - 1, _c, n) && arr[r - 1][_c] == 'x') return -1;
  while (_c + 1 < n && arr[r][_c + 1] == 'x') {
    ++_c;
    if (valid_coord(r - 1, _c, n) && arr[r - 1][_c] == 'x') return -1;
    if (used[r][_c]) return -1;
    used[r][_c];
  }
  ll _r = r;
  if (valid_coord(_r, _c + 1, n) && arr[_r][_c + 1] == 'x') return -1;
  while (_r + 1 < n && arr[_r + 1][_c] == 'x') {
    ++_r;
    if (valid_coord(_r, _c + 1, n) && arr[_r][_c + 1] == 'x') return -1;
    if (used[_r][_c]) return -1;
    used[_r][_c] = true;
  }
  if (_r - r != _c - c) return -1;
  ll delta = _r - r;
  while (_c - 1 >= 0 && arr[_r][_c - 1] == 'x') {
    --_c;
    if (valid_coord(_r + 1, _c, n) && arr[_r + 1][_c] == 'x') return -1;
    if (used[_r][_c]) return -1;
    used[_r][_c] = true;
  }
  if (c != _c) return -1;
  if (valid_coord(_r, _c - 1, n) && arr[_r][_c - 1] == 'x') return -1;
  while (_r - 1 >= 0 && arr[_r - 1][_c] == 'x') {
    --_r;
    if (valid_coord(_r, _c - 1, n) && arr[_r][_c - 1] == 'x') return -1;
    if (used[_r][_c]) return -1;
    used[_r][_c] = true;
  }
  if (r != _r) return -1;
  return delta;
}

ppll find_max_subsquare(const vector<string> &arr) {
  vector<vector<bool>> used(arr.size(), vector<bool>(arr.size()));
  ll max_delta = -1;
  ppll res = {{-1, -1}, {-1, -1}};
  for (ll i = 0; i < arr.size(); ++i) {
    for (ll j = 0; j < arr.size(); ++j) {
      if (!used[i][j] && arr[i][j] == 'x') {
        ll delta = check_subsquare(i, j, arr, used);
        if (delta > max_delta) {
          max_delta = delta;
          res = {{i, j}, {i + delta, j + delta}};
        }
      }
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
