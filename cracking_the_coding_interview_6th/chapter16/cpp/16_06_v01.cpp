#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll min_diff(const vector<ll> &v1, const vector<ll> &v2) {
  vector<pll> v;
  for (ll i = 0; i < v1.size(); ++i) {
    v.push_back({v1[i], 1});
  }
  for (ll i = 0; i < v2.size(); ++i) {
    v.push_back({v2[i], 2});
  }
  sort(v.begin(), v.end());
  ll mi = v[v.size() - 1].first - v[0].first;
  for (ll i = 0; i < v.size() - 1; ++i) {
    if (v[i].second != v[i + 1].second) {
      mi = min(mi, v[i + 1].first - v[i].first);
    }
  }
  return mi;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  vector<ll> v1(n), v2(m);
  for (ll i = 0; i < n; ++i) {
    ifs >> v1[i];
  }
  for (ll i = 0; i < m; ++i) {
    ifs >> v2[i];
  }
  printf("%lld\n\n", min_diff(v1, v2));
}

int main() {
  solve("../testcases/16_06/01.txt");
  solve("../testcases/16_06/02.txt");
  solve("../testcases/16_06/03.txt");
}

// # ../testcases/16_06/01.txt
// 3

// # ../testcases/16_06/02.txt
// 1

// # ../testcases/16_06/03.txt
// 1