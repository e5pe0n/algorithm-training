#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void perm(string pre, string rem, vector<string> &res) {
  if (rem.size() == 0) {
    res.push_back(pre);
    return;
  }
  for (ll i = 0; i < rem.size(); ++i) {
    string before = rem.substr(0, i);
    string after = rem.substr(i + 1);
    perm(pre + rem[i], before + after, res);
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
// abcd
// abdc
// acbd
// acdb
// adbc
// adcb
// bacd
// badc
// bcad
// bcda
// bdac
// bdca
// cabd
// cadb
// cbad
// cbda
// cdab
// cdba
// dabc
// dacb
// dbac
// dbca
// dcab
// dcba