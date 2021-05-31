#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll bs(const vector<string> &v, const string &x) {
  ll left = 0;
  ll right = v.size() - 1;
  bool to_left = true;
  while (left <= right) {
    ll mid = (left + right) / 2;
    ll _mid = mid;
    while (_mid >= left && _mid <= right && v[_mid] == "") {
      if (to_left)
        --_mid;
      else
        ++_mid;
    }
    if (_mid < left)
      left = mid;
    else if (_mid > right)
      right = mid;
    else if (v[_mid] < x)
      left = _mid + 1;
    else if (v[_mid] > x)
      right = _mid - 1;
    else
      return _mid;
    to_left = !to_left;
  }
  return -1;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n;
  string x;
  ifs >> n >> x;
  vector<ll> spaces(n + 1);
  for (ll i = 0; i < n + 1; ++i)
    ifs >> spaces[i];
  vector<string> ss(n);
  for (ll i = 0; i < n; ++i)
    ifs >> ss[i];
  vector<string> v(spaces[0], "");
  for (ll i = 0; i < n; ++i) {
    v.push_back(ss[i]);
    for (ll j = 0; j < spaces[i + 1]; ++j)
      v.push_back("");
  }
  cout << bs(v, x) << "\n" << endl;
}

int main() {
  solve("../testcases/10_05/01.txt");
  solve("../testcases/10_05/02.txt");
}