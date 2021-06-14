#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Dict {
  map<string, set<string>> d2w_map;
  static map<char, ll> _c2d_map;
  static map<char, ll> make_c2d_map();
  bool __insert(string word, string digits) {
    if (word.size() == digits.size()) {
      d2w_map[digits].insert(word);
      return true;
    }
    return __insert(word, digits + to_string(_c2d_map[word[digits.size()]]));
  }

public:
  Dict() {}
  bool insert(string word) {
    return __insert(word, "");
  }
  vector<string> search(string digits) {
    set<string> &s = d2w_map[digits];
    vector<string> res(s.begin(), s.end());
    return res;
  }
};

map<char, ll> Dict::make_c2d_map() {
  vector<string> d2c{
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  map<char, ll> c2d;
  for (ll i = 0; i < d2c.size(); ++i) {
    for (auto c : d2c[i]) {
      c2d[c] = i;
    }
  }
  return c2d;
}

map<char, ll> Dict::_c2d_map = make_c2d_map();

void solve(const string &fp, Dict &d) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string digits;
  ifs >> digits;
  auto res = d.search(digits);
  for (auto s : res) {
    puts(s.c_str());
  }
  puts("");
}

int main() {
  Dict d;
  ifstream ifs{"../testcases/16_20/words.txt"};
  for (string s; getline(ifs, s);) {
    d.insert(s);
  }
  solve("../testcases/16_20/01.txt", d);
  solve("../testcases/16_20/02.txt", d);
  solve("../testcases/16_20/03.txt", d);
  solve("../testcases/16_20/04.txt", d);
}

// # ../testcases/16_20/01.txt
// tree
// used

// # ../testcases/16_20/02.txt

// # ../testcases/16_20/03.txt
// machine

// # ../testcases/16_20/04.txt
// defect
// effect