// Cracking the Coding Interview p.263
#include <fstream>
#include <list>
#include <memory>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Node {
  ll x;
  shared_ptr<Node> left, right;
  Node(ll _x) : Node(_x, nullptr, nullptr) {}
  Node(ll _x, shared_ptr<Node> _left, shared_ptr<Node> _right)
      : x(_x), left(_left), right(_right) {}
  string to_str() {
    return "(" + (left ? left->to_str() : "null") + " " + to_string(x) + " "
           + (right ? right->to_str() : "null") + ")";
  }
};

struct Tree {
  shared_ptr<Node> root;
  Tree(shared_ptr<Node> _root) : root(_root) {}
  string to_str() {
    return root ? root->to_str() : "null";
  }
};

shared_ptr<Node> conn_nodes(const vector<shared_ptr<Node>> &nodes,
                            const ll &left,
                            const ll &right) {
  if (right - left == 0) return nullptr;
  if (right - left == 1) return nodes[left];
  ll mid = (left + right) / 2;
  nodes[mid]->left = conn_nodes(nodes, left, mid);
  nodes[mid]->right = conn_nodes(nodes, mid + 1, right);
  return nodes[mid];
}

shared_ptr<Tree> make_bst(const ll &n) {
  vector<shared_ptr<Node>> nodes(n);
  for (ll i = 0; i < n; ++i) {
    nodes[i] = make_shared<Node>(i);
  }
  return make_shared<Tree>(conn_nodes(nodes, 0, n));
}

void weave_list(list<ll> &fst,
                list<ll> &snd,
                vector<list<ll>> &ress,
                list<ll> &pre) {
  if (fst.size() == 0 || snd.size() == 0) {
    list<ll> res = pre;
    for (auto &i : fst)
      res.push_back(i);
    for (auto &i : snd)
      res.push_back(i);
    ress.push_back(res);
    return;
  }

  ll head_fst = fst.front();
  fst.pop_front();
  pre.push_back(head_fst);
  weave_list(fst, snd, ress, pre);
  pre.pop_back();
  fst.push_front(head_fst);

  ll head_snd = snd.front();
  snd.pop_front();
  pre.push_back(head_snd);
  weave_list(fst, snd, ress, pre);
  pre.pop_back();
  snd.push_front(head_snd);
}

vector<list<ll>> _all_sequences(shared_ptr<Node> node) {
  vector<list<ll>> res;
  if (node == nullptr) {
    res.emplace_back(list<ll>{});
    return res;
  }
  list<ll> pre;
  pre.push_back(node->x);

  vector<list<ll>> left_seq = _all_sequences(node->left);
  vector<list<ll>> right_seq = _all_sequences(node->right);

  for (auto &left : left_seq) {
    for (auto &right : right_seq) {
      vector<list<ll>> weaved;
      weave_list(left, right, weaved, pre);
      for (auto &w : weaved) {
        res.push_back(w);
      }
    }
  }
  return res;
}

vector<list<ll>> all_sequences(shared_ptr<Tree> tree) {
  return _all_sequences(tree->root);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  shared_ptr<Tree> tree = make_bst(n);
  vector<list<ll>> res = all_sequences(tree);
  for (ll i = 0; i < res.size(); ++i) {
    for (auto it = res[i].begin(); it != res[i].end(); ++it) {
      printf("%lld%c", *it + 1, it == --(res[i].end()) ? '\n' : ' ');
    }
  }
  puts("");
}

int main() {
  solve("../testcases/04_09/01.txt");
  solve("../testcases/04_09/02.txt");
  solve("../testcases/04_09/03.txt");
}

// output is too long to be shown