#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll MAX_L = 63;

struct Node {
  vector<Node> nodes;
  bool terminate = false;

  void _insert(const string &s, const ll idx) {
    if (idx == s.size()) {
      terminate = true;
      return;
    }
    if (nodes.size() == 0) { nodes = vector<Node>(26); }
    nodes[s[idx] - 'a']._insert(s, idx + 1);
  }

  void insert(const string &s) {
    _insert(s, 0);
  }

  bool _search(const string &s, const ll idx) {
    if (idx == s.size()) { return terminate; }
    if (nodes.size() == 0) return false;
    return nodes[s[idx] - 'a']._search(s, idx + 1);
  }

  bool search(const string &s) {
    return _search(s, 0);
  }
};

struct Trie {
  Node root;
  void insert(const string &s) {
    root.insert(s);
  }
  void insert_all(const vector<string> &words) {
    for (auto s : words) {
      insert(s);
    }
  }
  bool search(const string &s) {
    return root.search(s);
  }
  Trie() {}
  Trie(const vector<string> &words) {
    insert_all(words);
  }
};

ll max_size(const vector<string> &words) {
  ll ma = 0;
  for (auto s : words) {
    ma = max(ma, (ll)s.size());
  }
  return ma;
}

vector<vector<string>> sizes(const vector<string> &words) {
  vector<vector<string>> sizes(MAX_L);
  for (const auto &s : words) {
    sizes[s.size()].push_back(s);
  }
  return sizes;
}

vector<string> make_wr(vector<string> &vs,
                       vector<string> &hs,
                       vector<string> &v_choices,
                       vector<string> &h_choices,
                       ll idx,
                       ll n,
                       Trie &trie) {
  vector<string> res;
  if (idx == n) {
    bool found = true;
    for (ll i = 0; i < vs[0].size(); ++i) {
      string s;
      for (const auto &v : vs) {
        s += v[i];
      }
      if (!trie.search(s)) {
        found = false;
        break;
      }
    }
    for (ll j = 0; j < hs[0].size(); ++j) {
      string s;
      for (const auto &h : hs) {
        s += h[j];
      }
      if (!trie.search(s)) {
        found = false;
        break;
      }
    }
    return found ? hs : res;
  }
  for (const auto &v : v_choices) {
    for (const auto &h : h_choices) {
      if (v[idx] == h[idx]) {
        vs.push_back(v);
        hs.push_back(h);
        vector<string> r =
            make_wr(vs, hs, v_choices, h_choices, idx + 1, n, trie);
        if (r.size()) return r;
        vs.pop_back();
        hs.pop_back();
      }
    }
  }
  return res;
}

vector<string> max_wr(const vector<string> &words) {
  Trie trie{words};
  ll max_len = max_size(words);
  vector<vector<string>> zs = sizes(words);
  ll max_wr_size = 0;
  vector<string> res;
  for (ll n_rows = 1; n_rows <= max_len; ++n_rows) {
    for (ll n_cols = 1; n_cols <= n_rows; ++n_cols) {
      vector<string> vs, hs;
      vector<string> wr =
          make_wr(vs, hs, zs[n_rows], zs[n_cols], 0, n_cols, trie);
      if (wr.size()) {
        ll wr_size = wr.size() * wr[0].size();
        if (wr_size > max_wr_size) {
          max_wr_size = wr_size;
          res = wr;
        }
      }
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  set<string> word_set;
  for (ll i = 0; i < n; ++i) {
    string s;
    ifs >> s;
    word_set.insert(s);
  }
  vector<string> words(word_set.begin(), word_set.end());
  vector<string> res = max_wr(words);
  for (const auto &s : res)
    puts(s.c_str());
  puts("");
}

int main() {
  solve("../testcases/17_25/01.txt");
}