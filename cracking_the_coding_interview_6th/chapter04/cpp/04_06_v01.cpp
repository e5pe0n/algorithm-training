#include <fstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using tllc = tuple<ll, ll, char>;

struct Node {
  ll idx, x;
  Node *par = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(ll _idx, ll _x, Node *_par, Node *_left, Node *_right)
      : idx(_idx), x(_x), par(_par), left(_left), right(_right) {}
  Node(ll _idx, ll _x) : Node(_idx, _x, nullptr, nullptr, nullptr) {}
  ~Node() {
    delete left;
    delete right;
  }
  string to_str() {
    return "(" + (left ? left->to_str() : "null") + " " + to_string(x) + " "
           + (right ? right->to_str() : "null") + ")";
  }
};

struct Tree {
  Node *root;
  Tree(Node *_root) : root(_root) {}
  ~Tree() {
    delete root;
  }
  string to_str() {
    return root ? root->to_str() : "null";
  }
};

Tree *make_tree(const vector<ll> &v, const vector<tllc> &edges) {
  vector<Node *> nodes;
  for (ll i = 0; i < v.size(); ++i) {
    nodes.emplace_back(new Node(i, v[i]));
  }
  for (const auto &[u, v, c] : edges) {
    if (c == 'l') {
      nodes[u]->left = nodes[v];
      nodes[v]->par = nodes[u];
    } else if (c == 'r') {
      nodes[u]->right = nodes[v];
      nodes[v]->par = nodes[u];
    }
  }
  return new Tree(nodes[0]);
}

Node *_get_node(Node *node, ll node_idx) {
  if (node == nullptr) return nullptr;
  if (node->idx == node_idx)
    return node;
  else {
    Node *node_l = _get_node(node->left, node_idx);
    Node *node_r = _get_node(node->right, node_idx);
    if (node_l) return node_l;
    if (node_r) return node_r;
    return nullptr;
  }
}

Node *get_node(Tree *tree, ll node_idx) {
  return _get_node(tree->root, node_idx);
}

Node *get_succ(Tree *tree, ll node_idx) {
  Node *node = get_node(tree, node_idx);
  if (!node) return nullptr;
  if (node->right) {
    node = node->right;
    while (node->left) {
      node = node->left;
    }
    return node;
  }
  Node *par = node->par;
  while (par && par->left != node) {
    node = par;
    par = node->par;
  }
  return par;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, k;
  ifs >> n >> k;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  vector<tllc> edges(n - 1);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    edges[i] = make_tuple(--u, --v, c);
  }
  Tree *tree = make_tree(v, edges);
  Node *res = get_succ(tree, k - 1);
  printf("%s\n", res ? to_string(res->idx + 1).c_str() : "null");
  puts("");
  delete tree;
}

int main() {
  solve("../testcases/04_06/01.txt");
  solve("../testcases/04_06/02.txt");
  solve("../testcases/04_06/03.txt");
  solve("../testcases/04_06/04.txt");
  solve("../testcases/04_06/05.txt");
}

// # ../testcases/04_06/01.txt
// 11

// # ../testcases/04_06/02.txt
// 12

// # ../testcases/04_06/03.txt
// 1

// # ../testcases/04_06/04.txt
// 6

// # ../testcases/04_06/05.txt
// null
