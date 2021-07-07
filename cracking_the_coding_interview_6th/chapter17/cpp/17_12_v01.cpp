#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

template <typename T> struct BiNode {
  BiNode<T> *node1 = nullptr, *node2 = nullptr;
  T value;
  BiNode() {}
};

template <typename T> string repr_bt(BiNode<T> *root) {
  stringstream ss;
  if (root == nullptr) return "null";
  ss << "(" << repr_bt(root->node1);
  ss << " " << root->value << " ";
  ss << repr_bt(root->node2) << ")";
  return ss.str();
}

template <typename T> string repr_dll(BiNode<T> *node) {
  BiNode<T> *start = node;
  stringstream ss;
  ss << "["
     << "(" << start->node1->value << " " << start->value << " "
     << start->node2->value << "), ";
  node = node->node2;
  while (node != start) {
    ss << "(" << node->node1->value << " " << node->value << " "
       << node->node2->value << "), ";
    node = node->node2;
  }
  string res = ss.str();
  res.pop_back();
  res.pop_back();
  return res += "]";
}

template <typename T> void bt2v(BiNode<T> *node, vector<BiNode<T> *> &nodes) {
  if (node == nullptr) return;
  bt2v(node->node1, nodes);
  nodes.push_back(node);
  bt2v(node->node2, nodes);
}

template <typename T> void bt2dll(BiNode<T> *root) {
  // convert given a binary tree to a doubly linked list
  vector<BiNode<T> *> nodes;
  bt2v(root, nodes);
  ll n = nodes.size();
  for (ll i = 0; i < n; ++i) {
    nodes[i]->node1 = nodes[((i - 1) % n + n) % n];
    nodes[i]->node2 = nodes[(i + 1) % n];
  }
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<BiNode<ll>> nodes(n);
  for (ll i = 0; i < n; ++i) {
    ll value, left_node, right_node;
    ifs >> value >> left_node >> right_node;
    nodes[i].value = value;
    if (left_node > 0) nodes[i].node1 = &nodes[left_node - 1];
    if (right_node > 0) nodes[i].node2 = &nodes[right_node - 1];
  }
  puts(repr_bt(&nodes[0]).c_str());
  bt2dll(&nodes[0]);
  puts(repr_dll(&nodes[0]).c_str());
}

int main() {
  solve("../testcases/17_12/01.txt");
}

// # ../testcases/17_12/01.txt
// (((null 1 null) 2 ((null 3 null) 4 (null 5 null))) 6 (((null 7 (null 8 null))
// 9 null) 10 ((null 11 null) 12 (null 13 null))))
// [(5 6 7), (6 7 8), (7 8 9), (8 9 10), (9 10 11), (10 11 12), (11 12 13), (12
// 13 1), (13 1 2), (1 2 3), (2 3 4), (3 4 5), (4 5 6)]
