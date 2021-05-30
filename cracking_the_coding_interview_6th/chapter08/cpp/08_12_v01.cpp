#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void eight_queen(ll row,
                 vector<bool> &cols,
                 vector<bool> &diags1,
                 vector<bool> &diags2,
                 vector<pll> &curr,
                 vector<vector<pll>> &res) {
  if (row == 8) {
    res.push_back(curr);
    return;
  }
  for (ll col = 0; col < 8; ++col) {
    if (!cols[col] && !diags1[row + col] && !diags2[row - col + 7]) {
      cols[col] = diags1[row + col] = diags2[row - col + 7] = true;
      curr.push_back({row, col});
      eight_queen(row + 1, cols, diags1, diags2, curr, res);
      cols[col] = diags1[row + col] = diags2[row - col + 7] = false;
      curr.pop_back();
    }
  }
}

void solve() {
  vector<bool> cols(8);
  vector<bool> diags1(16);
  vector<bool> diags2(16);
  vector<pll> curr;
  vector<vector<pll>> res;
  eight_queen(0, cols, diags1, diags2, curr, res);
  cout << res.size() << endl;
  for (ll i = 0; i < 10; ++i) {
    for (ll j = 0; j < 8; ++j) {
      printf("(%lld, %lld)%c",
             res[i][j].first,
             res[i][j].second,
             j == 7 ? '\n' : ' ');
    }
  }
}

int main() {
  solve();
}

// 92
// (0, 0) (1, 4) (2, 7) (3, 5) (4, 2) (5, 6) (6, 1) (7, 3)
// (0, 0) (1, 5) (2, 7) (3, 2) (4, 6) (5, 3) (6, 1) (7, 4)
// (0, 0) (1, 6) (2, 3) (3, 5) (4, 7) (5, 1) (6, 4) (7, 2)
// (0, 0) (1, 6) (2, 4) (3, 7) (4, 1) (5, 3) (6, 5) (7, 2)
// (0, 1) (1, 3) (2, 5) (3, 7) (4, 2) (5, 0) (6, 6) (7, 4)
// (0, 1) (1, 4) (2, 6) (3, 0) (4, 2) (5, 7) (6, 5) (7, 3)
// (0, 1) (1, 4) (2, 6) (3, 3) (4, 0) (5, 7) (6, 5) (7, 2)
// (0, 1) (1, 5) (2, 0) (3, 6) (4, 3) (5, 7) (6, 2) (7, 4)
// (0, 1) (1, 5) (2, 7) (3, 2) (4, 0) (5, 3) (6, 6) (7, 4)
// (1, 1) (1, 6) (2, 2) (3, 5) (4, 7) (5, 4) (6, 0) (7, 3)