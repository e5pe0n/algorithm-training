// Cracking the Coding Interview p.271
#include <chrono>
#include <memory>
#include <random>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using hrc = chrono::high_resolution_clock;

class Node {
private:
  ll _data, _size;
  shared_ptr<Node> left, right;

public:
  Node(ll d) : _data(d) {
    _size = 1;
  }

  ll data() {
    return _data;
  }

  ll size() {
    return _size;
  }

  shared_ptr<Node> get_ith_node(ll i) {
    ll left_size = left ? left->size() : 0;
    if (i < left_size)
      return left->get_ith_node(i);
    else if (i == left_size)
      return left;
    else
      return right->get_ith_node(i - (left_size + 1));
  }

  void insert_in_order(ll d) {
    if (d <= _data) {
      if (!left)
        left = make_shared<Node>(d);
      else
        left->insert_in_order(d);
    } else {
      if (!right)
        right = make_shared<Node>(d);
      else
        right->insert_in_order(d);
    }
    ++_size;
  }

  shared_ptr<Node> find(ll d) {
    if (d == _data)
      return make_shared<Node>(*this);
    else if (d <= _data)
      return left ? left->find(d) : nullptr;
    else if (d > _data)
      return right ? right->find(d) : nullptr;
    return nullptr;
  }
};

class Tree {
public:
  shared_ptr<Node> root;
  ll size() {
    return root ? root->size() : 0;
  }

  shared_ptr<Node> get_random_node() {
    // O(log n)
    if (!root) return nullptr;
    auto seed = hrc::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<ll> distribution(0, size() - 1);
    ll x = distribution(generator);
    return root->get_ith_node(x);
  }

  void insert_in_order(ll value) {
    if (!root)
      root = make_shared<Node>(value);
    else
      root->insert_in_order(value);
  }
};