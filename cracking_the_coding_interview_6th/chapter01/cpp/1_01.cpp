#include <functional>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

bool is_unique1(string s) {
  for (ll i = 0; i < s.size() - 1; ++i) {
    for (ll j = i + 1; j < s.size(); ++j) {
      if (s[i] == s[j]) return false;
    }
  }
  return true;
}

bool is_unique2(string s) {
  set<char> st(s.begin(), s.end());
  return st.size() == s.size();
}

bool is_unique3(string s) {
  vector<bool> bs(255);
  for (auto c : s) {
    if (bs[c]) return false;
    bs[c] = true;
  }
  return true;
}

bool is_unique4(string s) {
  sort(s.begin(), s.end());
  for (ll i = 0; i < s.size() - 1; ++i) {
    if (s[i + 1] == s[i]) return false;
  }
  return true;
}

bool is_unique5(string s) {
  ll b;
  for (auto c : s) {
    if (b & (1 << c)) return false;
    b |= 1 << c;
  }
  return true;
}

void show(const function<bool(string)> &f,
          const string &fn,
          const vector<string> &ss) {
  printf("# %s\n", fn.c_str());
  for (auto s : ss) {
    printf("%s is %s\n", s.c_str(), f(s) ? "unique" : "not unique");
  }
  puts("");
}

int main() {
  vector<string> ss{"abcde", "aabcd", "abcbe", "abcda"};
  show(is_unique1, "is_unique1", ss);
  show(is_unique2, "is_unique2", ss);
  show(is_unique3, "is_unique3", ss);
  show(is_unique4, "is_unique4", ss);
  show(is_unique5, "is_unique5", ss);
}