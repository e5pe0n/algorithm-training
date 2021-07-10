#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

map<string, vector<ll>> find_pos(const string &s, const vector<string> &T) {
  map<char, vector<ll>> begins;
  for (ll i = 0; i < s.size(); ++i) {
    begins[s[i]].push_back(i);
  }
  map<string, vector<ll>> pos;
  for (auto t : T) {
    for (auto i : begins[t[0]]) {
      if (t == s.substr(i, t.size())) pos[t].push_back(i);
    }
  }
  return pos;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string s;
  ifs >> s;
  ll n;
  ifs >> n;
  vector<string> T(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> T[i];
  }
  map<string, vector<ll>> res = find_pos(s, T);
  for (const auto &[w, v] : res) {
    printf("%s: ", w.c_str());
    for (ll i = 0; i < v.size(); ++i) {
      printf("%lld%c", v[i], i == v.size() - 1 ? '\n' : ' ');
    }
  }
  puts("");
}

int main() {
  solve("../testcases/17_17/01.txt");
  solve("../testcases/17_17/02.txt");
}

// # ../testcases/17_17/01.txt
// computer: 27
// data: 99
// is: 15
// machinelearningisthestudyofcomputeralgorithmsthatimproveautomaticallythroughexperienceandbytheuseofdat:
// 0 of: 25 97 the: 17 91

// # ../testcases/17_17/02.txt
// computer: 23 113 200 313 619 822
// handwritten: 963
// is: 33 211 336 562 637 660 678 732 746 787 951
// machine: 0 250 474 573
// of: 571 651 712 759 917 961 983
// that: 148
// the: 46 152 247 292 310 407 471 505 558 761 792 819 839 910 946