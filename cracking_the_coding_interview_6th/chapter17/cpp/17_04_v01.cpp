#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll _find_missing(const vector<ll> &v, ll i) {
  if (v.size() == 0) return 0;
  vector<ll> zeros;
  vector<ll> ones;
  ll mask = 1 << i;
  for (auto n : v) {
    if (n & mask)
      ones.push_back(n);
    else
      zeros.push_back(n);
  }
  if (zeros.size() <= ones.size()) {
    ll res = _find_missing(zeros, i + 1);
    return (res << 1) | 0;
  } else {
    ll res = _find_missing(ones, i + 1);
    return (res << 1) | 1;
  }
}

ll find_missing(const vector<ll> &v) {
  return _find_missing(v, 0);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  printf("%lld\n", find_missing(v));
  puts("");
}

int main() {
  solve("../testcases/17_04/01.txt");
  solve("../testcases/17_04/02.txt");
}

// # ../testcases/17_04/01.txt
// 3

// # ../testcases/17_04/02.txt
// 47
