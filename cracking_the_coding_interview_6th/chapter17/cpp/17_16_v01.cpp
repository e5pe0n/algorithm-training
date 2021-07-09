#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll UNIT = 15;
const ll MAX_MINUTES = 100'000;

ll max_minutes(vector<ll> v) {
  vector<ll> ms(MAX_MINUTES);
  ll total = 0;
  for (auto _v : v) {
    _v /= UNIT;
    ms[total] = _v;
    total += _v;
  }
  vector<ll> dp(total + 2);
  for (ll i = 0; i <= total; ++i) {
    if (i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1]);
    ll _i = i + ms[i] + 1;
    dp[_i] = max(dp[_i], dp[i] + ms[i]);
  }
  return dp[total + 1] * UNIT;
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
  printf("%lld\n", max_minutes(v));
  puts("");
}

int main() {
  solve("../testcases/17_16/01.txt");
  solve("../testcases/17_16/02.txt");
  solve("../testcases/17_16/03.txt");
}

// # ../testcases/17_16/01.txt
// 180

// # ../testcases/17_16/02.txt
// 330
