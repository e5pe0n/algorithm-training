#include <algorithm>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> find_pairs(vector<ll> v, const ll sum) {
  sort(v.begin(), v.end());
  set<pll> s;
  for (auto n : v) {
    ll diff = sum - n;
    auto it = lower_bound(v.begin(), v.end(), diff);
    if (it != v.end() && *it + n == sum) s.insert({min(n, *it), max(n, *it)});
  }
  vector<pll> res(s.begin(), s.end());
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, sum;
  ifs >> n >> sum;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  vector<pll> res = find_pairs(v, sum);
  for (ll i = 0; i < res.size(); ++i) {
    printf("(%lld, %lld)%s",
           res[i].first,
           res[i].second,
           i == res.size() - 1 ? "\n" : ", ");
  }
  puts("");
}

int main() {
  solve("../testcases/16_24/01.txt");
  solve("../testcases/16_24/02.txt");
}

// # ../testcases/16_24/01.txt
// (0, 6), (2, 4)

// # ../testcases/16_24/02.txt
// (-91, 47), (-63, 19), (-62, 18), (-49, 5), (-47, 3), (-45, 1), (-44, 0),
// (-39, -5), (-36, -8)
