#include <fstream>
#include <math.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, char> tllc;

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
  vector<Node *> nodes;
  for (ll i = 0; i < n; ++i) {
    nodes.emplace_back(new Node(i));
  }
  for (const auto &[u, v, c] : edges) {
    if (c == 'l')
      nodes[u]->left = nodes[v];
    else if (c == 'r')
      nodes[u]->right = nodes[v];
  }
  return new Tree(nodes[0]);
}

struct Res {
  ll height;
  bool balanced;
};

Res dfs(Node *node) {
  if (node->left == nullptr && node->right == nullptr) return Res{0, true};
  Res res_l, res_r;
  if (node->right == nullptr) {
    res_l = dfs(node->left);
    return Res{res_l.height + 1, res_l.balanced};
  }
  if (node->left == nullptr) {
    res_r = dfs(node->right);
    return Res{res_r.height + 1, res_r.balanced};
  }
  res_l = dfs(node->left);
  res_r = dfs(node->right);
  return Res{max(res_l.height, res_r.height) + 1,
             abs(res_l.height - res_r.height) <= 1 && res_l.balanced
                 && res_r.balanced};
}

bool is_balanced(Tree *tree) {
  if (tree->root == nullptr) return false;
  Res res = dfs(tree->root);
  return res.balanced;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<tllc> edges(n - 1);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    edges[i] = make_tuple(--u, --v, c);
  }
  Tree *tree = make_tree(n, edges);
  printf("%s\n", is_balanced(tree) ? "balanced" : "unbalanced");
  puts("");
  delete tree;
}

int main() {
  solve("../testcases/04_04/01.txt");
  solve("../testcases/04_04/02.txt");
  solve("../testcases/04_04/03.txt");
  solve("../testcases/04_04/04.txt");
}

// # ../testcases/04_04/01.txt
// balanced

// # ../testcases/04_04/02.txt
// balanced

// # ../testcases/04_04/03.txt
// unbalanced

// # ../testcases/04_04/04.txt
// unbalanced
