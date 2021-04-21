#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct Node {
  ll x;
  Node *left, *right;
  Node(ll _x, Node *_left, Node *_right) : x(_x), left(_left), right(_right) {}
  ~Node() {
    delete left;
    delete right;
  }
  string to_str() {
    return "(" + (left == nullptr ? "null" : left->to_str()) + " "
           + to_string(x) + " " + (right == nullptr ? "null" : right->to_str())
           + ")";
  }
};

struct Tree {
  Node *root;
  Tree(Node *_root) : root(_root) {}
  ~Tree() {
    delete root;
  }
  string to_str() {
    return root == nullptr ? "null" : root->to_str();
  }
};

Node *rec(const vector<ll> &v, ll left, ll right) {
  if (right - left == 0) return nullptr;
  if (right - left == 1) return new Node(v[left], nullptr, nullptr);
  ll mid = (right + left) / 2;
  Node *lc = rec(v, left, mid);
  Node *rc = rec(v, mid + 1, right);
  Node *par = new Node(v[mid], lc, rc);
  return par;
}

Tree *make_min_bst(const vector<ll> &v) {
  return new Tree(rec(v, 0, v.size()));
}

void _make_depth_list(Node *node, ll depth, vector<vector<Node *>> &res) {
  if (node == nullptr) return;
  if (res.size() <= depth) res.push_back(vector<Node *>());
  res[depth].push_back(node);
  _make_depth_list(node->left, depth + 1, res);
  _make_depth_list(node->right, depth + 1, res);
}

vector<vector<Node *>> make_depth_list(Tree *tree) {
  vector<vector<Node *>> res;
  _make_depth_list(tree->root, 0, res);
  return res;
}

void show_list(const vector<vector<Node *>> &v) {
  for (ll i = 0; i < v.size(); ++i) {
    printf("%lld: ", i);
    for (ll j = 0; j < v[i].size(); ++j) {
      printf("%lld%c", v[i][j]->x, j == v[i].size() - 1 ? '\n' : ' ');
    }
  }
}

void solve(const string &fp) {
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  Tree *tree = make_min_bst(v);
  vector<vector<Node *>> res = make_depth_list(tree);
  printf("# %s\n", fp.c_str());
  show_list(res);
  puts("");
  delete tree;
}

int main() {
  solve("../testcases/04_03/01.txt");
  solve("../testcases/04_03/02.txt");
  solve("../testcases/04_03/03.txt");
  solve("../testcases/04_03/04.txt");
}

// # ../testcases/04_03/01.txt
// 0: 4
// 1: 2 6
// 2: 1 3 5 7

// # ../testcases/04_03/02.txt
// 0: 5
// 1: 3 7
// 2: 2 4 6 8
// 3: 1

// # ../testcases/04_03/03.txt
// 0: 6
// 1: 3 9
// 2: 2 5 8 10
// 3: 1 4 7

// # ../testcases/04_03/04.txt
// 0: 2
// 1: 1