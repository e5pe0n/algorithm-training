#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll find_kth_mul(vector<ll> ps, ll k) {
  vector<ll> muls{1};
  for (ll i = 1; i < k; ++i) {
    vector<ll> v;
    for (auto p : ps) {
      for (auto m : muls) {
        if (p * m > muls[i - 1]) v.push_back(p * m);
      }
    }
    ll mi = v[0];
    for (auto _v : v) {
      if (mi > _v) mi = _v;
    }
    muls.push_back(mi);
  }
  return muls[k - 1];
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, k;
  ifs >> n >> k;
  vector<ll> ps(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> ps[i];
  }
  printf("%lld\n", find_kth_mul(ps, k));
  puts("");
}

int main() {
  solve("../testcases/17_09/01.txt");
  solve("../testcases/17_09/02.txt");
  solve("../testcases/17_09/03.txt");
}

// # ../testcases/17_09/01.txt
// 21

// # ../testcases/17_09/02.txt
// 65536

// # ../testcases/17_09/03.txt
// 24
