#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void perm(string &pre, map<char, ll> &cnt, const ll len, vector<string> &res) {
  if (pre.size() == len) {
    res.push_back(pre);
    return;
  }
  for (auto [c, n] : cnt) {
    if (n > 0) {
      --cnt[c];
      pre += c;
      perm(pre, cnt, len, res);
      pre.pop_back();
      ++cnt[c];
    }
  }
}

void solve(string s) {
  cout << "# " << s << endl;
  map<char, ll> cnt;
  for (auto c : s) {
    ++cnt[c];
  }
  vector<string> res;
  string pre{};
  perm(pre, cnt, s.size(), res);
  cout << res.size() << endl;
  for (const auto &s : res)
    cout << s << endl;
  cout << endl;
}

int main() {
  solve("aaabbc");
}

// # aaabbc
// 60
// aaabbc
// aaabcb
// aaacbb
// aababc
// aabacb
// aabbac
// aabbca
// aabcab
// aabcba
// aacabb
// aacbab
// aacbba
// abaabc
// abaacb
// ababac
// ababca
// abacab
// abacba
// abbaac
// abbaca
// abbcaa
// abcaab
// abcaba
// abcbaa
// acaabb
// acabab
// acabba
// acbaab
// acbaba
// acbbaa
// baaabc
// baaacb
// baabac
// baabca
// baacab
// baacba
// babaac
// babaca
// babcaa
// bacaab
// bacaba
// bacbaa
// bbaaac
// bbaaca
// bbacaa
// bbcaaa
// bcaaab
// bcaaba
// bcabaa
// bcbaaa
// caaabb
// caabab
// caabba
// cabaab
// cababa
// cabbaa
// cbaaab
// cbaaba
// cbabaa
// cbbaaa
