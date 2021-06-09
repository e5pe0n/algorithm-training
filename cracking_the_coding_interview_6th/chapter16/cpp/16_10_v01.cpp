// Space complexity 2 * year_range is worse than 1 * year_range of v02
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll max_year(vector<ll> births, vector<ll> deads) {
  vector<ll> bs(101), ds(101);
  for (ll i = 0; i < births.size(); ++i) {
    ++bs[births[i] - 1900];
    ++ds[deads[i] - 1900];
  }
  ll ma_cnt = 0;
  ll ma_year = 0;
  ll cnt = 0;
  for (ll year = 1900; year <= 2000; ++year) {
    cnt += bs[year - 1900];
    if (cnt > ma_cnt) {
      ma_cnt = cnt;
      ma_year = year;
    }
    cnt -= ds[year - 1900];
  }
  return ma_year;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> births(n);
  vector<ll> deads(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> births[i] >> deads[i];
  }
  printf("%lld\n", max_year(births, deads));
  puts("");
}

int main() {
  solve("../testcases/16_10/01.txt");
  solve("../testcases/16_10/02.txt");
}

// # ../testcases/16_10/01.txt
// 1935

// # ../testcases/16_10/02.txt
// 1964
