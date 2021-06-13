#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll max_sum(const vector<ll> &v) {
  ll n = v.size();
  vector<ll> sum(n + 1);
  for (ll i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + v[i];
  }
  ll res = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i; j < n; ++j) {
      res = max(res, sum[j + 1] - sum[i]);
    }
  }
  return res;
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
  printf("%lld\n", max_sum(v));
  puts("");
}

int main() {
  solve("../testcases/16_17/01.txt");
  solve("../testcases/16_17/02.txt");
  solve("../testcases/16_17/03.txt");
}

// # ../testcases/16_17/01.txt
// 5

// # ../testcases/16_17/02.txt
// 192

// # ../testcases/16_17/03.txt
// 225
