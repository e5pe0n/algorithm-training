#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct SearchRes {
  bool found = false;
  ll term_cnt = 0;
};

class Node {
  vector<Node> _nodes;
  bool _terminate = false;
  void _insert(string const &s, ll idx) {
    if (idx == s.size()) {
      _terminate = true;
      return;
    }
    if (_nodes.size() == 0) _nodes = vector<Node>(26);
    _nodes[s[idx] - 'a']._insert(s, idx + 1);
  }
  SearchRes _search(const string &s, ll idx, ll term_cnt) {
    if (idx == s.size()) return SearchRes{_terminate, term_cnt + _terminate};
    if (_nodes.size() == 0) return SearchRes{false};
    return _nodes[s[idx] - 'a']._search(s, idx + 1, term_cnt + _terminate);
  }

public:
  void insert(const string &s) {
    _insert(s, 0);
  }
  SearchRes search(const string &s) {
    return _search(s, 0, 0);
  }
};

class Trie {
  Node _root;

public:
  Trie(){};
  void insert(const string &s) {
    _root.insert(s);
  }
  void insert_all(const vector<string> &v) {
    for (auto s : v)
      _root.insert(s);
  }
  SearchRes search(const string &s) {
    return _root.search(s);
  }
};

string longest_composite_word(const vector<string> &v) {
  Trie trie{};
  trie.insert_all(v);
  string res{};
  for (auto s : v) {
    if (s.size() < res.size()) continue;
    SearchRes search_res = trie.search(s);
    // printf("%s, %d, %lld\n", s.c_str(), search_res.found,
    // search_res.term_cnt);
    if (search_res.term_cnt > 1) res = s;
  }
  return res;
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