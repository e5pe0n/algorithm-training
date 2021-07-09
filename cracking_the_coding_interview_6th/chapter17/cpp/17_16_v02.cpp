// Cracking the Coding Interview p.577
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll max_minutes(vector<ll> v) {
  ll one_away = 0;
  ll two_away = 0;
  for (ll i = v.size() - 1; i >= 0; --i) {
    ll best_with = v[i] + two_away;
    ll best_without = one_away;
    two_away = one_away;
    one_away = max(best_with, best_without);
  }
  return one_away;
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

// # ../testcases/17_16/03.txt
// 330