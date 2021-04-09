#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<string, string> ps;

bool is_perm1(string s, string t) {
  if (s.size() != t.size()) return false;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

bool is_perm2(string s, string t) {
  if (s.size() != t.size()) return false;
  vector<ll> cnt_s(255), cnt_t(255);
  for (ll i = 0; i < s.size(); ++i) {
    ++cnt_s[s[i]];
    ++cnt_t[t[i]];
  }
  for (auto c : s) {
    if (cnt_s[c] != cnt_t[c]) return false;
  }
  return true;
}

bool is_perm3(string s, string t) {
  if (s.size() != t.size()) return false;
  vector<ll> cnt(255);
  for (auto c : s) {
    ++cnt[c];
  }
  for (auto c : t) {
    if (--cnt[c] < 0) return false;
  }
  return true;
}

void show(const function<bool(string, string)> &f,
          const string &fn,
          const vector<ps> ss) {
  printf("# %s\n", fn.c_str());
  for (auto s : ss) {
    string fst = s.first, snd = s.second;
    printf("%s is %s of %s\n",
           fst.c_str(),
           is_perm1(fst, snd) ? "permutation" : "not permutation",
           snd.c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_02.txt");
  ll n;
  ifs >> n;
  vector<ps> ss;
  for (ll i = 0; i < n; ++i) {
    string fst, snd;
    ifs >> fst >> snd;
    ss.push_back({fst, snd});
  }
  show(is_perm1, "is_perm1", ss);
  show(is_perm2, "is_perm2", ss);
  show(is_perm3, "is_perm3", ss);
}