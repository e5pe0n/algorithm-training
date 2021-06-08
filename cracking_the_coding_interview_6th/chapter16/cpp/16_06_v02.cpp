#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e9;

ll min_diff(vector<ll> v1, vector<ll> v2) {
  if (v1.size() == 0 || v2.size() == 0) return INF;
  if (v1.size() > v2.size()) swap(v1, v2);
  sort(v1.begin(), v1.end());
  ll mi = INF;
  for (auto n : v2) {
    auto it = lower_bound(v1.begin(), v1.end(), n);
    if (it == v1.end()) --it;
    mi = min(mi, abs(*it - n));
    if (it != v1.begin()) mi = min(mi, abs(*(it - 1) - n));
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
