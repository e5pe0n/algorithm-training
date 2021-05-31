#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e18;

class Listy {
  vector<ll> _v;

public:
  Listy(const vector<ll> &v) : _v(v) {}
  ll operator[](const size_t &i) {
    if (i < _v.size()) return _v[i];
    return -1;
  }
};

ll search(Listy &listy, const ll x) {
  ll left = 0;
  ll right = INF;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (listy[mid] == -1)
      right = mid;
    else if (listy[mid] <= x)
      left = mid;
    else
      right = mid;
  }
  if (listy[left] == x) return left;
  return -1;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, x;
  ifs >> n >> x;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i)
    ifs >> v[i];
  Listy listy{v};
  cout << search(listy, x) << "\n" << endl;
}

int main() {
  solve("../testcases/10_04/01.txt");
  solve("../testcases/10_04/02.txt");
}

// # ../testcases/10_04/01.txt
// 7

// # ../testcases/10_04/02.txt
// 18
