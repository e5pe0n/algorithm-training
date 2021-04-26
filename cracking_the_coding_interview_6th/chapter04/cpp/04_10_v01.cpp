#include <fstream>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using tllc = tuple<ll, ll, char>;

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

shared_ptr<Tree> make_bt(const ll &root,
                         const vector<ll> &node_idxs,
                         const vector<tllc> &edges) {
  map<ll, shared_ptr<Node>> nodes;
  for (auto &idx : node_idxs) {
    nodes[idx] = make_shared<Node>(idx);
  }
  for (auto &e : edges) {
    if (get<2>(e) == 'l') {
      nodes[get<0>(e)]->left = nodes[get<1>(e)];
    } else {
      nodes[get<0>(e)]->right = nodes[get<1>(e)];
    }
  }
  return make_shared<Tree>(nodes[root]);
}

bool is_same_tree(shared_ptr<Node> node1, shared_ptr<Node> node2) {
  if (node1 == nullptr && node2 == nullptr) return true;
  if (node1 == nullptr || node2 == nullptr) return false;
  if (node1->x != node2->x) return false;
  return is_same_tree(node1->left, node2->left)
         && is_same_tree(node1->right, node2->right);
}

bool _is_subtree(shared_ptr<Node> node, shared_ptr<Node> sub_root) {
  if (node == nullptr) return false;
  if (node->x == sub_root->x && is_same_tree(node, sub_root)) return true;
  if (_is_subtree(node->left, sub_root)) return true;
  return _is_subtree(node->right, sub_root);
}

bool is_subtree(shared_ptr<Tree> tree, shared_ptr<Tree> sub) {
  return _is_subtree(tree->root, sub->root);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, a;
  ifs >> n >> a;
  vector<ll> node_idxs1 = vector<ll>(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> node_idxs1[i];
  }
  vector<tllc> edges1 = vector<tllc>(n - 1);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    edges1[i] = make_tuple(u, v, c);
  }
  ll m, b;
  ifs >> m >> b;
  vector<ll> node_idxs2 = vector<ll>(m);
  for (ll i = 0; i < m; ++i) {
    ifs >> node_idxs2[i];
  }
  vector<tllc> edges2 = vector<tllc>(m - 1);
  for (ll i = 0; i < m - 1; ++i) {
    ll p, q;
    char c;
    ifs >> p >> q >> c;
    edges2[i] = make_tuple(p, q, c);
  }
  shared_ptr<Tree> t1 = make_bt(a, node_idxs1, edges1);
  shared_ptr<Tree> t2 = make_bt(b, node_idxs2, edges2);
  puts(is_subtree(t1, t2) ? "true" : "false");
  puts("");
}

int main() {
  solve("../testcases/04_10/01.txt");
  solve("../testcases/04_10/02.txt");
  solve("../testcases/04_10/03.txt");
  solve("../testcases/04_10/04.txt");
  solve("../testcases/04_10/05.txt");
  solve("../testcases/04_10/06.txt");
  solve("../testcases/04_10/07.txt");
  solve("../testcases/04_10/08.txt");
  solve("../testcases/04_10/09.txt");
}

// # ../testcases/04_10/01.txt
// true

// # ../testcases/04_10/02.txt
// true

// # ../testcases/04_10/03.txt
// true

// # ../testcases/04_10/04.txt
// true

// # ../testcases/04_10/05.txt
// true

// # ../testcases/04_10/06.txt
// false

// # ../testcases/04_10/07.txt
// false

// # ../testcases/04_10/08.txt
// false

// # ../testcases/04_10/09.txt
// false
