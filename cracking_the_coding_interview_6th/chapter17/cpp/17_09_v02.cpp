// Cracking the Coding Interview p.531
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll rm_min(vector<ll> &v) {
  ll mi = v[0];
  for (auto _v : v) {
    if (mi > _v) mi = _v;
  }
  vector<ll> v2;
  for (auto _v : v)
    if (_v != mi) v2.push_back(_v);
  v = v2;
  return mi;
}

void add_products(vector<ll> &v, ll val, vector<ll> &ps) {
  for (auto p : ps) {
    v.push_back(p * val);
  }
}

ll find_kth_mul(vector<ll> ps, ll k) {
  if (k < 0) return 0;

  ll val = 1;
  vector<ll> v{val};
  for (ll i = 0; i < k; ++i) {
    val = rm_min(v);
    add_products(v, val, ps);
  }
  return val;
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