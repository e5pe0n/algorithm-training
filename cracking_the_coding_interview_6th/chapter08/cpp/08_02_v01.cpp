#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool valid(ll i, ll j, ll n, ll m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void print_path(const vector<vector<pll>> &path, ll i, ll j) {
  if (i == -1 && j == -1) return;
  print_path(path, path[i][j].first, path[i][j].second);
  cout << "(" << i << ", " << j << ")" << endl;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  vector<string> S(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> S[i];
  }
  ll inf = m * n;
  pll no_reach = {inf, inf};
  vector<vector<pll>> prev_path(n, vector<pll>(m, {inf, inf}));
  prev_path[0][0] = {-1, -1};
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (prev_path[i][j] == no_reach) continue;
      if (valid(i, j + 1, n, m) && S[i][j + 1] != 'x') {
        prev_path[i][j + 1] = {i, j};
      }
      if (valid(i + 1, j, n, m) && S[i + 1][j] != 'x') {
        prev_path[i + 1][j] = {i, j};
      }
    }
  }
  if (prev_path[n - 1][m - 1] == no_reach) {
    cout << "no reach" << endl;
  } else {
    print_path(prev_path, n - 1, m - 1);
  }
  cout << endl;
}

int main() {
  solve("../testcases/08_02/01.txt");
  solve("../testcases/08_02/02.txt");
}