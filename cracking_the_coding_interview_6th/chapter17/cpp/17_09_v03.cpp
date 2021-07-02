// Cracking the Coding Interview p.533
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll find_kth_mul(vector<ll> ps, ll k) {
  vector<queue<ll>> qs;
  for (auto p : ps) {
    qs.push_back(queue<ll>{});
  }
  ll val = 0;
  qs[0].push(1);
  for (ll _ = 0; _ < k; ++_) {
    ll mi = qs[0].front();
    ll mi_idx = 0;
    for (ll i = 0; i < ps.size(); ++i) {
      if (qs[i].size() && mi > qs[i].front()) {
        mi = qs[i].front();
        mi_idx = i;
      }
    }
    val = mi;
    qs[mi_idx].pop();
    for (ll i = mi_idx; i < qs.size(); ++i) {
      qs[i].push(mi * ps[i]);
    }
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