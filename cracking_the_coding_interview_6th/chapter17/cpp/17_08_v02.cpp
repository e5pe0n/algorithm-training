#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll find_max_height(vector<pll> hw) {
  sort(hw.begin(), hw.end());
  vector<vector<ll>> vs;
  ll res = 0;
  for (ll i = 0; i < hw.size(); ++i) {
    vector<ll> _v;
    vector<ll> *v = &_v;
    for (ll j = 0; j < i; ++j) {
      if (*(vs[j].end() - 1) < hw[i].second && v->size() < vs[j].size()) {
        v = &(vs[j]);
      }
    }
    vs.emplace_back(v->begin(), v->end());
    vs[i].push_back(hw[i].second);
    res = max(res, (ll)vs[i].size());
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<pll> hw(n);
  for (ll i = 0; i < n; ++i) {
    ll h, w;
    ifs >> h >> w;
    hw[i] = {h, w};
  }
  printf("%lld\n", find_max_height(hw));
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