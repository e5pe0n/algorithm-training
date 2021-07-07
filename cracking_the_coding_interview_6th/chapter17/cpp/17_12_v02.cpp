#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

template <typename T> struct BiNode {
  BiNode<T> *node1 = nullptr, *node2 = nullptr;
  T value;
  BiNode() {}
};

template <typename T> using pnn = pair<BiNode<T> *, BiNode<T> *>;

template <typename T> string repr_bt(BiNode<T> *root) {
  if (root == nullptr) return "null";
  stringstream ss;
  ss << "(" << repr_bt(root->node1);
  ss << " " << root->value << " ";
  ss << repr_bt(root->node2) << ")";
  return ss.str();
}

template <typename T> string repr_dll(BiNode<T> *node) {
  BiNode<T> *start = node;
  stringstream ss;
  ss << "[";
  ss << "(" << node->node1->value;
  ss << " " << node->value << " ";
  ss << node->node2->value << "), ";
  node = node->node2;
  while (node != start) {
    ss << "(" << node->node1->value;
    ss << " " << node->value << " ";
    ss << node->node2->value << "), ";
    node = node->node2;
  }
  string res = ss.str();
  res.pop_back();
  res.pop_back();
  return res += "]";
}

template <typename T> pnn<T> _bt2dll(BiNode<T> *node) {
  if (node == nullptr) return {nullptr, nullptr};
  auto [left_head, left_tail] = _bt2dll(node->node1);
  auto [right_head, right_tail] = _bt2dll(node->node2);
  if (left_head && right_head) {
    left_tail->node2 = node;
    node->node1 = left_tail;
    node->node2 = right_head;
    right_head->node1 = node;
    right_tail->node2 = left_head;
    left_head->node1 = right_tail;
    return {left_head, right_tail};
  } else if (left_head) {
    left_tail->node2 = node;
    node->node1 = left_tail;
    node->node2 = left_head;
    left_head->node1 = node;
    return {left_head, node};
  } else if (right_head) {
    node->node2 = right_head;
    right_head->node1 = node;
    right_tail->node2 = node;
    node->node1 = right_tail;
    return {node, right_tail};
  } else {
    return {node, node};
  }
}

template <typename T> void bt2dll(BiNode<T> *root) {
  _bt2dll(root);
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
