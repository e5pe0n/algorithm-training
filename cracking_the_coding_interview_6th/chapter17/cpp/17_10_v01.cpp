// Cracking the Coding Interview p.557
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

bool validate(const vector<ll> v, const ll majority) {
  ll cnt = 0;
  for (auto _v : v) {
    if (_v == majority) ++cnt;
  }
  return cnt > v.size() / 2;
}

ll get_candidate(const vector<ll> v) {
  ll majority = 0;
  ll cnt = 0;
  for (auto _v : v) {
    if (cnt == 0) majority = _v;
    if (_v == majority)
      ++cnt;
    else
      --cnt;
  }
  return majority;
}

ll find_majority_elem(const vector<ll> v) {
  ll candidate = get_candidate(v);
  return validate(v, candidate) ? candidate : -1;
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
  printf("%lld\n", find_majority_elem(v));
  puts("");
}

int main() {
  solve("../testcases/17_10/01.txt");
  solve("../testcases/17_10/02.txt");
  solve("../testcases/17_10/03.txt");
  solve("../testcases/17_10/04.txt");
  solve("../testcases/17_10/05.txt");
}

// # ../testcases/17_10/01.txt
// 5

// # ../testcases/17_10/02.txt
// -1

// # ../testcases/17_10/03.txt
// 2

// # ../testcases/17_10/04.txt
// 1000000000

// # ../testcases/17_10/05.txt
// 5
