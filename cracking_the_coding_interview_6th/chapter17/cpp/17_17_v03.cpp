// Cracking the Coding Interview p.582
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Node;
class ProceedRes;

class Node {
  map<char, Node> nodes;
  bool _terminate = false;
  void _insert(const string &s, const ll idx) {
    if (idx == s.size()) {
      _terminate = true;
      return;
    }
    nodes[s[idx]]._insert(s, idx + 1);
  }

public:
  ProceedRes proceed(const char);
  bool terminate() {
    return _terminate;
  }
  void insert(const string &s) {
    _insert(s, 0);
  }
};

struct ProceedRes {
  bool succeeded = false;
  Node nxt;
};

ProceedRes Node::proceed(const char c) {
  if (nodes.find(c) == nodes.end()) return ProceedRes{false};
  return ProceedRes{true, nodes[c]};
}

class Trie {
  Node root;
  Node curr;

public:
  Trie() {
    curr = root;
  }
  Trie(const vector<string> &v) {
    insert_all(v);
    curr = root;
  }
  void insert(const string &s) {
    root.insert(s);
  }
  void insert_all(const vector<string> &v) {
    for (const auto &s : v) {
      root.insert(s);
    }
  }
  ProceedRes next_node(const char c) {
    ProceedRes res = curr.proceed(c);
    curr = res.nxt;
    return res;
  }
  void reset_curr() {
    curr = root;
  }
};

map<string, vector<ll>> search_all(const string &s, const vector<string> &T) {
  Trie trie(T);
  map<string, vector<ll>> lookup;
  for (ll i = 0; i < s.size(); ++i) {
    for (ll j = i; j < s.size(); ++j) {
      ProceedRes res = trie.next_node(s[j]);
      if (!res.succeeded) break;
      if (res.succeeded && res.nxt.terminate())
        lookup[s.substr(i, j - i + 1)].push_back(i);
    }
    trie.reset_curr();
  }
  return lookup;
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
  map<string, vector<ll>> res = search_all(s, T);
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
