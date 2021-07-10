// Cracking the Coding Interview p.579
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Node {
  map<char, Node> nodes;
  vector<ll> idxs;
  bool terminate = false;
  vector<ll> _search(const string &s, const ll cnt) {
    if (cnt == s.size()) return idxs;
    if (nodes.size() == 0) return {};
    return nodes[s[cnt]]._search(s, cnt + 1);
  }

public:
  Node() {}
  void insert(const string &s, const ll idx, const ll cnt) {
    idxs.push_back(idx);
    if (cnt == s.size()) {
      terminate = true;
      return;
    }
    nodes[s[cnt]].insert(s, idx + 1, cnt + 1);
  }
  vector<ll> search(const string &s) {
    return _search(s, 0);
  }
};

class Trie {
  Node root;

public:
  void insert(const string &s, const ll idx) {
    root.insert(s, idx, 0);
  }
  vector<ll> search(const string &s) {
    return root.search(s);
  }
};

void adjust_idx(vector<ll> &idxs, const ll delta) {
  for (ll i = 0; i < idxs.size(); ++i) {
    idxs[i] -= delta;
  }
}

Trie create_trie(const string &s) {
  Trie trie;
  for (ll i = 0; i < s.size(); ++i) {
    trie.insert(s.substr(i), i);
  }
  return trie;
}

map<string, vector<ll>> search_all(string s, vector<string> T) {
  map<string, vector<ll>> lookup;
  Trie trie = create_trie(s);
  for (const auto &t : T) {
    vector<ll> idxs = trie.search(t);
    adjust_idx(idxs, t.size());
    lookup[t] = idxs;
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
  for (const auto &[w, idxs] : res) {
    printf("%s: ", w.c_str());
    for (ll i = 0; i < idxs.size(); ++i) {
      printf("%lld%c", idxs[i], i == idxs.size() - 1 ? '\n' : ' ');
    }
    if (idxs.size() == 0) puts("");
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