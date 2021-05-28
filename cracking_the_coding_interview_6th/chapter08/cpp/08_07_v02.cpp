#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void perm(string pre, const string &org, vector<string> &res) {
  if (pre.size() == org.size()) {
    res.push_back(pre);
    return;
  }
  for (ll i = 0; i <= pre.size(); ++i) {
    string nxt{pre};
    nxt.insert(i, 1, org[pre.size()]);
    perm(nxt, org, res);
  }
}

void solve(string s) {
  cout << "# " << s << endl;
  sort(s.begin(), s.end());
  vector<string> res;
  perm("", s, res);
  for (auto r : res)
    cout << r << endl;
  cout << endl;
}

int main() {
  solve("abcd");
}

// # abcd
// dcba
// cdba
// cbda
// cbad
// dbca
// bdca
// bcda
// bcad
// dbac
// bdac
// badc
// bacd
// dcab
// cdab
// cadb
// cabd
// dacb
// adcb
// acdb
// acbd
// dabc
// adbc
// abdc
// abcd