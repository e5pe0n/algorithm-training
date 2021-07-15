#include <fstream>
#include <limits>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Res {
  ll sum = numeric_limits<ll>::min();
  pll topleft;
  pll btmright;
};

Res find_max_submat(const vector<vector<ll>> &mat) {
  ll n = mat.size();
  ll m = mat[0].size();
  vector<vector<ll>> sums(n + 1, vector<ll>(m + 1));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      sums[i][j + 1] = sums[i][j] + mat[i][j];
    }
  }
  Res res;
  for (ll left = 0; left < m; ++left) {
    for (ll right = left; right < m; ++right) {
      ll t = 0;
      ll _i = 0;
      for (ll i = 0; i < n; ++i) {
        t += sums[i][right + 1] - sums[i][left];
        if (t > res.sum) {
          res.sum = t;
          res.topleft = {_i, left};
          res.btmright = {i, right};
        }
        if (t < 0) {
          _i = i + 1;
          t = 0;
        }
      }
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, m;
  ifs >> n >> m;
  vector<vector<ll>> mat(n, vector<ll>(m));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      ifs >> mat[i][j];
    }
  }
  Res res = find_max_submat(mat);
  printf("%lld, ((%lld, %lld), (%lld, %lld))\n",
         res.sum,
         res.topleft.first,
         res.topleft.second,
         res.btmright.first,
         res.btmright.second);
  puts("");
}

int main() {
  solve("../testcases/17_24/01.txt");
  solve("../testcases/17_24/02.txt");
  solve("../testcases/17_24/03.txt");
  solve("../testcases/17_24/04.txt");
  solve("../testcases/17_24/05.txt");
  solve("../testcases/17_24/06.txt");
}

// # ../testcases/17_24/01.txt
// 16, ((3, 0), (3, 1))

// # ../testcases/17_24/02.txt
// 30, ((1, 1), (4, 3))

// # ../testcases/17_24/03.txt
// 33, ((7, 0), (9, 4))

// # ../testcases/17_24/04.txt
// -1, ((5, 0), (5, 0))

// # ../testcases/17_24/05.txt
// 38, ((8, 0), (9, 4))

// # ../testcases/17_24/06.txt
// 111, ((0, 0), (4, 4))
