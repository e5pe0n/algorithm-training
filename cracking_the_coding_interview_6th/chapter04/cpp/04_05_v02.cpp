#include <fstream>
#include <limits>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using tllc = tuple<ll, ll, char>;

const ll MAX = numeric_limits<ll>::max();

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

Tree *make_tree(const vector<ll> &v, const vector<tllc> &edges) {
  vector<Node *> nodes;
  for (const auto &x : v) {
    nodes.emplace_back(new Node(x));
  }
  for (const auto &[u, v, c] : edges) {
    if (c == 'l')
      nodes[u]->left = nodes[v];
    else if (c == 'r')
      nodes[u]->right = nodes[v];
  }
  return new Tree(nodes[0]);
}

bool is_within_range(const Node *node, const ll &lb, const ll &ub) {
  if (node == nullptr) return true;
  bool res_l = is_within_range(node->left, lb, node->x);
  bool res_r = is_within_range(node->right, node->x + 1, ub);
  bool res_n = lb <= node->x && node->x <= ub;
  return res_l && res_n && res_r;
}

bool is_valid_bst(const Tree *tree) {
  if (tree->root == nullptr) return false;
  return is_within_range(tree->root, -MAX, MAX);
}

void solve(string fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
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
  printf("%s\n", is_valid_bst(tree) ? "true" : "false");
  puts("");
  delete tree;
}

int main() {
  solve("../testcases/04_05/01.txt");
  solve("../testcases/04_05/02.txt");
  solve("../testcases/04_05/03.txt");
  solve("../testcases/04_05/04.txt");
  solve("../testcases/04_05/05.txt");
  solve("../testcases/04_05/06.txt");
  solve("../testcases/04_05/07.txt");
  solve("../testcases/04_05/08.txt");
  solve("../testcases/04_05/09.txt");
}

// # ../testcases/04_05/01.txt
// true

// # ../testcases/04_05/02.txt
// false

// # ../testcases/04_05/03.txt
// true

// # ../testcases/04_05/04.txt
// false

// # ../testcases/04_05/05.txt
// true

// # ../testcases/04_05/06.txt
// false

// # ../testcases/04_05/07.txt
// true

// # ../testcases/04_05/08.txt
// false

// # ../testcases/04_05/09.txt
// false