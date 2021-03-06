// implementation is correct but algorithm is wrong
#include <fstream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Node {
  ll x;
  shared_ptr<Node> left = nullptr;
  shared_ptr<Node> right = nullptr;
  Node(ll _x) : x(_x) {}
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

shared_ptr<Node>
conn_nodes(vector<shared_ptr<Node>> &nodes, ll left, ll right) {
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

vector<vector<shared_ptr<Node>>> make_nodes_list(shared_ptr<Tree> tree) {
  vector<vector<shared_ptr<Node>>> res;
  res.emplace_back(vector<shared_ptr<Node>>{tree->root});
  ll idx = 0;
  while (idx < res.size()) {
    vector<shared_ptr<Node>> v;
    for (auto &node : res[idx]) {
      if (node->left != nullptr) v.push_back(node->left);
      if (node->right != nullptr) v.push_back(node->right);
    }
    if (v.size()) res.push_back(v);
    ++idx;
  }
  return res;
}

void perm(const vector<vector<shared_ptr<Node>>> &nodes_list,
          ll idx,
          ll _idx,
          vector<shared_ptr<Node>> pre,
          vector<vector<shared_ptr<Node>>> &res) {
  if (idx == nodes_list.size()) {
    for (ll i = 0; i < res.size(); ++i) {
      for (ll j = 0; j < res[i].size(); ++j) {
        printf("%lld ", res[i][j]->x + 1);
      }
    }
    puts("");
    return;
  }
  if (_idx == nodes_list[idx].size()) {
    res[idx] = pre;
    perm(nodes_list, idx + 1, 0, vector<shared_ptr<Node>>{}, res);
    return;
  }
  for (ll i = 0; i <= pre.size(); ++i) {
    vector<shared_ptr<Node>> _pre(pre.begin(), pre.end());
    _pre.insert(_pre.begin() + i, nodes_list[idx][_idx]);
    perm(nodes_list, idx, _idx + 1, _pre, res);
  }
}

void print_lists(vector<vector<shared_ptr<Node>>> &nodes_list) {
  vector<vector<shared_ptr<Node>>> res(nodes_list.size());
  perm(nodes_list, 0, 0, vector<shared_ptr<Node>>{}, res);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  shared_ptr<Tree> tree = make_bst(n);
  vector<vector<shared_ptr<Node>>> nodes_list = make_nodes_list(tree);
  print_lists(nodes_list);
  puts("");
}

int main() {
  solve("../testcases/04_09/01.txt");
  solve("../testcases/04_09/02.txt");
  solve("../testcases/04_09/03.txt");
}