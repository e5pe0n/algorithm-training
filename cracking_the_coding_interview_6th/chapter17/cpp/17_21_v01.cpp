#include <fstream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max();

ll water_amount(const vector<ll> &data) {
  vector<ll> water(data.size(), INF);
  ll top = 0;
  for (ll i = 0; i < data.size(); ++i) {
    top = max(top, data[i]);
    water[i] = min(water[i], top - data[i]);
  }
  top = 0;
  for (ll i = data.size() - 1; i >= 0; --i) {
    top = max(top, data[i]);
    water[i] = min(water[i], top - data[i]);
  }
  ll amount = 0;
  for (auto v : water)
    amount += v;
  return amount;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<ll> data(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> data[i];
  }
  printf("%lld\n", water_amount(data));
  puts("");
}

int main() {
  solve("../testcases/17_21/01.txt");
  solve("../testcases/17_21/02.txt");
  solve("../testcases/17_21/03.txt");
  solve("../testcases/17_21/04.txt");
}

// # ../testcases/17_21/01.txt
// 26

// # ../testcases/17_21/02.txt
// 64

// # ../testcases/17_21/03.txt
// 101

// # ../testcases/17_21/04.txt
// 35