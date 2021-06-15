#include <exception>
#include <fstream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class EmptyListException : public exception {
  virtual const char *what() const throw() {
    return "list is empty";
  }
} ele;

class FullListException : public exception {
  virtual const char *what() const throw() {
    return "list is full";
  }
} fle;

template <typename T> struct Node {
  string key;
  T value;
  Node() {}
  Node(string _key, T _value) : key(_key), value(_value) {}
  shared_ptr<Node<T>> prv = nullptr;
  shared_ptr<Node<T>> nxt = nullptr;
  string repr() {
    stringstream ss;
    ss << "(" << key << ", " << value << ")";
    return ss.str();
  }
};

template <typename T> class LRUCache {
  ll _capacity;
  ll _size = 0;
  shared_ptr<Node<T>> _head = nullptr;
  shared_ptr<Node<T>> _tail = nullptr;
  map<string, shared_ptr<Node<T>>> _m;
  void prepend(shared_ptr<Node<T>> node) {
    if (!_head) {
      _head = _tail = node;
      return;
    }
    shared_ptr<Node<T>> h = _head;
    _head = node;
    _head->nxt = h;
    h->prv = _head;
  }
  void touch(shared_ptr<Node<T>> node) {
    if (node == _head) return;
    del(node);
    prepend(node);
  }
  void del(shared_ptr<Node<T>> node) {
    if (!_head) throw ele;
    if (node == _head) _head = node->nxt;
    if (node == _tail) _tail = node->prv;
    if (node->nxt) { node->nxt->prv = node->prv; }
    if (node->prv) { node->prv->nxt = node->nxt; }
  }

public:
  LRUCache(ll capacity) {
    if (capacity <= 0)
      throw invalid_argument{"capacity must be greater than 0."};
    _capacity = capacity;
  }
  ll size() {
    return _size;
  }
  void add(const string &key, const T &value) {
    shared_ptr<Node<T>> node = make_shared<Node<T>>(key, value);
    if (_m.find(key) == _m.end() && _size == _capacity) {
      del(_tail);
      prepend(node);
      return;
    }
    prepend(node);
    _m[key] = node;
    ++_size;
  }
  T get(const string &key, const T &default_value) {
    try {
      return operator[](key);
    } catch (const invalid_argument &ia) { return default_value; }
  }
  T operator[](const string &key) {
    if (_m.find(key) == _m.end())
      throw invalid_argument{"key=" + key + " not found"};
    shared_ptr<Node<T>> node = _m[key];
    touch(node);
    return node->value;
  }
  string repr() {
    shared_ptr<Node<T>> node = _head;
    string res;
    while (node) {
      res += node->repr();
      res += ' ';
      node = node->nxt;
    }
    if (res.size()) res.pop_back();
    return res;
  }
};

int main() {
  LRUCache<ll> c{5};
  c.add("a", 1);
  c.add("b", 2);
  c.add("c", 3);
  puts(c.repr().c_str()); // (c, 3) (b, 2) (a, 1)
  c["a"];
  puts(c.repr().c_str()); // (a, 1) (c, 3) (b, 2)
  c.add("e", 5);
  c.add("f", 6);
  puts(c.repr().c_str()); // (f, 6) (e, 5) (a, 1) (c, 3) (b, 2)
  c.add("g", 7);
  puts(c.repr().c_str()); // (g, 7) (f, 6) (e, 5) (a, 1) (c, 3)
  c.add("h", 8);
  puts(c.repr().c_str()); // (h, 8) (g, 7) (f, 6) (e, 5) (a, 1)
  c["a"];
  c.add("i", 9);
  puts(c.repr().c_str()); // (i, 9) (a, 1) (h, 8) (g, 7) (f, 6)
}