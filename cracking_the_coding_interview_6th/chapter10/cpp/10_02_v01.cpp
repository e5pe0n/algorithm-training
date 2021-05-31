#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<string> sort_anagrams(vector<string> v) {
  sort(v.begin(), v.end());
  map<string, vector<string>> anagrams;
  for (auto &s : v) {
    map<char, ll> cnt;
    for (auto c : s) {
      ++cnt[c];
    }
    string sorted{};
    for (auto [c, n] : cnt) {
      sorted += string(n, c);
    }
    anagrams[sorted].push_back(s);
  }
  vector<string> res;
  for (auto &[_, v] : anagrams) {
    for (auto &s : v) {
      res.push_back(s);
    }
  }
  return res;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<string> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  vector<string> res = sort_anagrams(v);
  for (auto s : res)
    cout << s << endl;
  cout << endl;
}

int main() {
  solve("../testcases/10_02/01.txt");
}

// # ../testcases/10_02/01.txt
// ananab
// banana
// nabana
// apple
// epapl
// lappe
// pleap
// cherry
// echyrr
// rcyrhe