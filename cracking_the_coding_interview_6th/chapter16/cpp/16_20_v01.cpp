#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Node {
  vector<Node> _nodes;
  set<string> _words;
  static map<char, ll> _c2d_map;
  vector<string> _search(string digits, ll idx) {
    if (idx == digits.size()) return words();
    if (_nodes.size() == 0) return {};
    return _nodes[digits[idx] - '0']._search(digits, idx + 1);
  }
  bool _insert(string s, ll idx) {
    if (idx == s.size()) {
      _words.insert(s);
      return true;
    }
    if (_nodes.size() == 0) _nodes = vector<Node>(10);
    return _nodes[_c2d_map[s[idx]]]._insert(s, idx + 1);
  }
  static map<char, ll> make_c2d_map();

public:
  Node() {}
  vector<string> words() {
    vector<string> ws(_words.begin(), _words.end());
    return ws;
  }
  vector<string> search(string digits) {
    if (digits == "") return {};
    return _search(digits, 0);
  }
  bool insert(string s) {
    return _insert(s, 0);
  }
};

map<char, ll> Node::make_c2d_map() {
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

map<char, ll> Node::_c2d_map = make_c2d_map();

class WordTree {
  Node root;

public:
  WordTree() {}
  bool insert(string s) {
    return root.insert(s);
  }
  bool insert_all(vector<string> words) {
    bool res = true;
    for (auto w : words) {
      res |= insert(w);
    }
    return res;
  }
  vector<string> search(string digits) {
    return root.search(digits);
  }
};

void solve(const string &fp, WordTree &wt) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string digits;
  ifs >> digits;
  vector<string> res = wt.search(digits);
  for (auto s : res) {
    printf("%s\n", s.c_str());
  }
  puts("");
}

int main() {
  ifstream ifs{"../testcases/16_20/words.txt"};
  WordTree wt;
  for (string s; getline(ifs, s);) {
    wt.insert(s);
  }
  solve("../testcases/16_20/01.txt", wt);
  solve("../testcases/16_20/02.txt", wt);
  solve("../testcases/16_20/03.txt", wt);
  solve("../testcases/16_20/04.txt", wt);
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
