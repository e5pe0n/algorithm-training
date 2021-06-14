// Cracking the Coding Interview p.500
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll max_sum(const vector<ll> &v) {
  ll ma_sum = 0;
  ll sum = 0;
  for (auto n : v) {
    sum += n;
    if (ma_sum < sum)
      ma_sum = sum;
    else if (sum < 0)
      sum = 0;
  }
  return ma_sum;
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
