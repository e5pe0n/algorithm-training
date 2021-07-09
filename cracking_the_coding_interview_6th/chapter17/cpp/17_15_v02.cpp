// Cracking the Coding Interview p.573
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
template <typename T, typename U> using umap = unordered_map<T, U>;

bool can_build_word(const string &s, bool is_org_word, umap<string, bool> &m) {
  if (m[s] && !is_org_word) return m[s];
  for (ll i = 1; i < s.size(); ++i) {
    string left = s.substr(0, i);
    string right = s.substr(i);
    if (m[left] && can_build_word(right, false, m)) return true;
  }
  return false;
}

string longest_composite_word(vector<string> v) {
  umap<string, bool> m;
  for (auto s : v)
    m[s] = true;
  sort(v.begin(), v.end(), [](const string &left, const string &right) {
    return left.size() > right.size();
  });
  for (auto s : v) {
    if (can_build_word(s, true, m)) return s;
  }
  return "";
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<string> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  puts(longest_composite_word(v).c_str());
  puts("");
}

int main() {
  solve("../testcases/17_15/01.txt");
  solve("../testcases/17_15/02.txt");
  solve("../testcases/17_15/03.txt");
  solve("../testcases/17_15/04.txt");
  solve("../testcases/17_15/05.txt");
}

// # ../testcases/17_15/01.txt
// dogwalker

// # ../testcases/17_15/02.txt
// dogcatwalker

// # ../testcases/17_15/03.txt
// dogcatwalkerwalknanabanana

// # ../testcases/17_15/04.txt
// timeline

// # ../testcases/17_15/05.txt
// informationtechnology
