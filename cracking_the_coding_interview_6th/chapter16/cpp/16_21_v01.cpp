#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Res {
  bool found = false;
  pll p;
};

Res find_pair(const vector<ll> &v1, const vector<ll> &v2) {
  ll sum1 = 0, sum2 = 0;
  for (auto n : v1)
    sum1 += n;
  for (auto n : v2)
    sum2 += n;
  set<ll> s;
  for (auto n : v2) {
    s.insert(sum2 - 2 * n);
  }
  for (auto n : v1) {
    auto it = s.find(sum1 - 2 * n);
    if (it != s.end()) { return Res{true, {n, (sum2 - *it) / 2}}; }
  }
  return Res{false};
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n1, n2;
  ifs >> n1 >> n2;
  vector<ll> v1(n1), v2(n2);
  for (ll i = 0; i < n1; ++i) {
    ifs >> v1[i];
  }
  for (ll i = 0; i < n2; ++i) {
    ifs >> v2[i];
  }
  Res res = find_pair(v1, v2);
  if (res.found) {
    printf("found: (%lld, %lld)\n", res.p.first, res.p.second);
  } else {
    puts("not found");
  }
  puts("");
}

int main() {
  solve("../testcases/16_21/01.txt");
  solve("../testcases/16_21/02.txt");
  solve("../testcases/16_21/03.txt");
}