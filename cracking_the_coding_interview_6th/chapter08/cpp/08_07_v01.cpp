#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void perm(string pre,
          vector<bool> &used,
          const string &org,
          vector<string> &res) {
  if (pre.size() == org.size()) {
    res.push_back(pre);
    return;
  }
  for (ll i = 0; i < org.size(); ++i) {
    if (!used[i]) {
      used[i] = true;
      perm(pre + org[i], used, org, res);
      used[i] = false;
    }
  }
}

void solve(string s) {
  cout << "# " << s << endl;
  sort(s.begin(), s.end());
  vector<string> res;
  vector<bool> used(s.size());
  perm("", used, s, res);
  for (auto r : res)
    cout << r << endl;
  cout << endl;
}

int main() {
  solve("abcd");
}