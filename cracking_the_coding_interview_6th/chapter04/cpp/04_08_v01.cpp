#include <fstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using tllc = tuple<ll, ll, char>;

struct Node {
  ll x;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(ll _x) : x(_x) {}
  Node(ll _x, Node *_left, Node *_right) : x(_x), left(_left), right(_right) {}
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

Tree *make_tree(const ll &n, const vector<tllc> &edges) {
  vector<Node *> nodes(n);
  for (ll i = 0; i < n; ++i) {
    nodes[i] = new Node(i);
  }
  for (const auto &[u, v, c] : edges) {
    if (c == 'l')
      nodes[u]->left = nodes[v];
    else if (c == 'r')
      nodes[u]->right = nodes[v];
  }
  return new Tree(nodes[0]);
}

tuple<Node *, bool> dfs(Node *node, Node *s, Node *t) {
  if (node == nullptr) return make_tuple(nullptr, false);
  if (node == s || node == t) return make_tuple(nullptr, true);
  auto res_l = dfs(node->left, s, t);
  if (get<0>(res_l)) return res_l;
  auto res_r = dfs(node->right, s, t);
  if (get<0>(res_r)) return res_r;
  if (get<1>(res_l) && get<1>(res_r)) return make_tuple(node, true);
  return make_tuple(nullptr, get<1>(res_l) || get<1>(res_r));
}

Node *search_first_common_ancestor(Tree *tree, Node *s, Node *t) {
  auto [ans, _] = dfs(tree->root, s, t);
  return ans;
}

Node *_get_node(Node *node, ll node_idx) {
  if (node == nullptr) return nullptr;
  if (node->x == node_idx) return node;
  Node *res_l = _get_node(node->left, node_idx);
  if (res_l) return res_l;
  Node *res_r = _get_node(node->right, node_idx);
  if (res_r) return res_r;
  return nullptr;
}

Node *get_node(Tree *tree, ll node_idx) {
  return _get_node(tree->root, node_idx);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, s, t;
  ifs >> n >> s >> t;
  --s, --t;
  vector<tllc> edges(n - 1);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    edges[i] = make_tuple(--u, --v, c);
  }
  Tree *tree = make_tree(n, edges);
  Node *des1 = get_node(tree, s);
  Node *des2 = get_node(tree, t);
  Node *res = search_first_common_ancestor(tree, des1, des2);
  printf("%s\n", res ? to_string(res->x + 1).c_str() : "null");
  puts("");
  delete tree;
}

int main() {
  solve("../testcases/04_08/01.txt");
  solve("../testcases/04_08/02.txt");
  solve("../testcases/04_08/03.txt");
  solve("../testcases/04_08/04.txt");
}

// # ../testcases/04_08/01.txt
// 2

// # ../testcases/04_08/02.txt
// 2

// # ../testcases/04_08/03.txt
// 1

// # ../testcases/04_08/04.txt
// null