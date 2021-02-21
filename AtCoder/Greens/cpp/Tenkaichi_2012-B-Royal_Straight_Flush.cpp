#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
map<char, vector<string>> M{{'S', vector<string>()},
                            {'H', vector<string>()},
                            {'D', vector<string>()},
                            {'C', vector<string>()}};
string N[] = {"10", "J", "Q", "K", "A"};

void show(char m, const vector<string> &res) {
  bool _f = false;
  for (auto r : res) {
    bool f = false;
    for (ll i = 0; i < 5; ++i) {
      if (r[0] == m && r.substr(1) == N[i]) { f = true; }
    }
    if (f) continue;
    _f = true;
    printf("%s", r.c_str());
  }
  if (_f)
    puts("");
  else
    puts("0");
}

int main() {
  cin >> s;
  vector<string> res;
  char m;
  string n;
  for (ll i = 0; i < s.size(); ++i) {
    bool f = false;
    for (auto p : M) {
      if (s[i] == p.first) {
        for (ll j = 0; j < 5; ++j) {
          if (n == N[j]) {
            M[m].push_back(m + n);
            if (M[m].size() >= 5) {
              show(m, res);
              return 0;
            }
          }
        }
        if (m) res.push_back(m + n);
        m = s[i];
        n = "";
        f = true;
        break;
      }
    }
    if (f) continue;
    n += s[i];
  }
  res.push_back(m + n);
  show(m, res);
}