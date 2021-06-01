#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll search_mat(const vector<vector<ll>> &mat, const ll x) {
  ll left = 0;
  for (ll i = mat.size() - 1; i >= 0; --i) {
    ll right = mat[0].size();
    if (mat[i][right - 1] < x) return {-1, -1};
    while (right - left > 1) {
      ll mid = (left + right) / 2;
      if (mat[i][mid] <= x)
        left = mid;
      else
        right = mid;
    }
    if (mat[i][left] == x) return {i, left};
    left = max(left - 1, 0LL);
  }
  return {-1, -1};
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, m, x;
  ifs >> n >> m >> x;
  vector<vector<ll>> mat(n, vector<ll>(m));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      ifs >> mat[i][j];
    }
  }
  auto res = search_mat(mat, x);
  cout << res.first << " " << res.second << "\n" << endl;
}

int main() {
  solve("../testcases/10_09/01.txt");
  solve("../testcases/10_09/02.txt");
  solve("../testcases/10_09/03.txt");
  solve("../testcases/10_09/04.txt");
  solve("../testcases/10_09/05.txt");
  solve("../testcases/10_09/06.txt");
  solve("../testcases/10_09/07.txt");
}

// # ../testcases/10_09/01.txt
// 1 3

// # ../testcases/10_09/02.txt
// 0 0

// # ../testcases/10_09/03.txt
// 0 9

// # ../testcases/10_09/04.txt
// 9 0

// # ../testcases/10_09/05.txt
// 9 9

// # ../testcases/10_09/06.txt
// -1 -1

// # ../testcases/10_09/07.txt
// 8 7