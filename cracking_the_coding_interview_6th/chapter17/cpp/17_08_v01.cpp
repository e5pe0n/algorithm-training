#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll dfs(vector<pll> hw, ll idx, ll h, ll last_w) {
  if (idx == hw.size()) return h;
  ll res = 0;
  if (last_w < hw[idx].second) {
    res = max(res, dfs(hw, idx + 1, h + 1, hw[idx].second));
  }
  res = max(res, dfs(hw, idx + 1, h, last_w));
  return res;
}

ll find_max_height(vector<pll> hw) {
  sort(hw.begin(), hw.end());
  return dfs(hw, 0, 0, -1);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<pll> v(n);
  for (ll i = 0; i < n; ++i) {
    ll h, w;
    ifs >> h >> w;
    v[i] = {h, w};
  }
  ll res = find_max_height(v);
  printf("%lld\n", res);
  puts("");
}

int main() {
  solve("../testcases/17_08/01.txt");
  solve("../testcases/17_08/02.txt");
  solve("../testcases/17_08/03.txt");
}

// # ../testcases/17_08/01.txt
// 6

// # ../testcases/17_08/02.txt
// 6

// # ../testcases/17_08/03.txt
// 1