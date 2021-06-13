#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll find_unsorted_range(const vector<ll> &v) {
  ll left = -1;
  ll right = -1;
  ll ma = v[0];
  for (ll i = 1; i < v.size(); ++i) {
    if (v[i] < ma) {
      right = i;
      if (left == -1) { left = i; }
      while (left > 0 && v[left - 1] > v[i])
        --left;
    } else {
      ma = v[i];
    }
  }
  return {left, right};
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
  auto [left, right] = find_unsorted_range(v);
  printf("%lld, %lld\n", left, right);
  puts("");
}

int main() {
  solve("../testcases/16_16/01.txt");
  solve("../testcases/16_16/02.txt");
  solve("../testcases/16_16/03.txt");
  solve("../testcases/16_16/04.txt");
}

// # ../testcases/16_16/01.txt
// 3 9

// # ../testcases/16_16/02.txt
// 6 14

// # ../testcases/16_16/03.txt
// -1 -1

// # ../testcases/16_16/04.txt
// -1 -1