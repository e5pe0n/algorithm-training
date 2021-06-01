#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class BT;
class Node;

struct Node {
  ll _x, _smallers;
  shared_ptr<Node> par, left, right;
  Node(ll x) : _x(x), _smallers(1) {}
  string repr() {
    return "(" + (left == nullptr ? "null" : left->repr()) + ") ["
           + to_string(_x) + "] " + to_string(_smallers) + " ("
           + (right == nullptr ? "null" : right->repr()) + ")";
  }
};

class BT {
  shared_ptr<Node> _root;

public:
  BT() {}
  BT(shared_ptr<Node> root) : _root(root) {}
  string repr() {
    return _root == nullptr ? "null" : _root->repr();
  }
  void track(ll x) {
    if (_root == nullptr) {
      _root = make_shared<Node>(x);
      return;
    }
    shared_ptr<Node> prev = nullptr;
    shared_ptr<Node> curr = _root;
    bool is_left = false;
    while (curr != nullptr) {
      if (curr->_x == x) {
        ++curr->_smallers;
        return;
      }
      prev = curr;
      if (curr->_x < x) {
        curr = curr->right;
        is_left = false;
      } else {
        ++curr->_smallers;
        curr = curr->left;
        is_left = true;
      }
    }
    shared_ptr<Node> node = make_shared<Node>(x);
    node->par = prev;
    if (is_left) {
      prev->left = node;
    } else {
      prev->right = node;
    }
  }
  ll get_rank(ll x) {
    if (_root == nullptr) return 0;
    shared_ptr<Node> curr = _root;
    ll rank = 0;
    while (curr != nullptr) {
      if (curr->_x == x) { return max(0LL, rank + curr->_smallers - 1); }
      if (curr->_x < x) {
        rank += curr->_smallers;
        curr = curr->right;
      } else {
        curr = curr->left;
      }
    }
    return rank;
  }
};

int main() {
  BT bt;
  vector<ll> v1{5, 1, 4, 4, 5, 9, 7, 13, 3};
  for (auto x : v1)
    bt.track(x);
  cout << bt.repr() << endl;
  printf("rank(%lld)=%lld\n", 1LL, bt.get_rank(1));
  printf("rank(%lld)=%lld\n", 3LL, bt.get_rank(3));
  printf("rank(%lld)=%lld\n", 4LL, bt.get_rank(4));
}