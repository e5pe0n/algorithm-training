#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool valid(const ll x, const ll y, const ll n, const ll m) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void paint_fill(const ll x,
                const ll y,
                vector<string> &screen,
                const char org,
                const char nw) {
  queue<pll> q;
  q.push({x, y});
  screen[x][y] = nw;
  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    for (ll di = -1; di <= 1; ++di) {
      for (ll dj = -1; dj <= 1; ++dj) {
        ll _i = i + di;
        ll _j = j + dj;
        if (valid(_i, _j, screen.size(), screen[0].size())
            && screen[_i][_j] == org) {
          screen[_i][_j] = nw;
          q.push({_i, _j});
        }
      }
    }
  }
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, m;
  char org, nw;
  ifs >> n >> m >> org >> nw;
  vector<string> screen(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> screen[i];
  }
  for (const auto &s : screen)
    cout << s << endl;
  cout << endl;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (screen[i][j] == org) paint_fill(i, j, screen, org, nw);
    }
  }
  for (const auto &s : screen)
    cout << s << endl;
  cout << endl;
}

int main() {
  solve("../testcases/08_10/01.txt");
}

// # ../testcases/08_10/01.txt
// .......x..
// .xxx..xx..
// .xxx..x.x.
// ......xxxx
// ...xx.....
// ..xxxx....
// ...xxxx...
// ...xxxx...
// ...x.....x
// x.....xxxx

// .......o..
// .ooo..oo..
// .ooo..o.o.
// ......oooo
// ...oo.....
// ..oooo....
// ...oooo...
// ...oooo...
// ...o.....o
// o.....oooo
