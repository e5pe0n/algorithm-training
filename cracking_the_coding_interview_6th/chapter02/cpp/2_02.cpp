#include <cassert>
#include <fstream>
#include <functional>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, string> pls;

struct Node {
  ll data;
  Node *next;
};

struct LinkedList {
  Node *head = nullptr;

  string to_str() {
    Node *node = head;
    string res = "[";
    while (node != nullptr) {
      res += to_string(node->data);
      res += " ";
      node = node->next;
    }
    if (res.size() > 1) res.pop_back();
    res += "]";
    return res;
  }

  void push(ll new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
  }

  void insert_after(Node *prev_node, ll new_data) {
    assert(prev_node != nullptr);

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
  }

  void append(ll new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (head == nullptr) {
      head = new_node;
      return;
    }

    Node *last = head;
    while (last->next != nullptr) {
      last = last->next;
    }
    last->next = new_node;
  }

  void delete_node(ll key) {
    Node *tmp = head;
    Node *prev = nullptr;

    // head has the key
    if (tmp != nullptr && tmp->data == key) {
      head = tmp->next;
      delete tmp;
      return;
    }

    while (tmp != nullptr && tmp->data != key) {
      prev = tmp;
      tmp = tmp->next;
    }

    // not found a node having the key
    if (tmp == nullptr) return;

    // found
    prev->next = tmp->next;
    delete tmp;
  }

  void delete_node_by_pos(ll pos) {
    if (head == nullptr) return;

    Node *tmp = head;

    if (pos == 0) {
      head = tmp->next;
      delete tmp;
      return;
    }

    for (ll _ = 0; _ < pos - 1; ++_) {
      tmp = tmp->next;
      if (tmp == nullptr) return;
    }

    if (tmp->next == nullptr) return;

    Node *node = tmp->next;
    tmp->next = node->next;
    delete node;
  }

  void delete_list() {
    Node *cur = head;
    Node *tmp = nullptr;

    while (cur != nullptr) {
      tmp = cur->next;
      delete cur;
      cur = tmp;
    }

    head = nullptr;
  }

  ll length() {
    ll cnt = 0;
    Node *cur = head;
    while (cur != nullptr) {
      cur = cur->next;
      ++cnt;
    }
    return cnt;
  }

  bool search(ll x) {
    Node *cur = head;
    while (cur != nullptr) {
      if (cur->data == x) return true;
      cur = cur->next;
    }
    return false;
  }

  ll get(ll pos) {
    Node *cur = head;
    ll cnt = 0;
    while (cur != nullptr) {
      if (cnt == pos) return cur->data;
      ++cnt;
      cur = cur->next;
    }
    throw "Index out of range";
  }

  ll last_kth1(ll k) {
    ll len = length();
    assert(k < len);
    Node *cur = head;
    ll cnt = len - k - 1;
    while (cnt--)
      cur = cur->next;
    return cur->data;
  }

  ll _last_kth2(Node *node, ll cnt) {
    if (cnt == 0) return node->data;
    return _last_kth2(node->next, cnt - 1);
  }

  ll last_kth2(ll k) {
    ll len = length();
    assert(k < len);
    return _last_kth2(head, len - k - 1);
  }

  ll _last_kth3(Node *node, ll k, ll &i) {
    if (node == nullptr) return -1;
    ll res = _last_kth3(node->next, k, i);
    if (i++ == k) return node->data;
    return res;
  }

  ll last_kth3(ll k) {
    ll i = 0;
    return _last_kth3(head, k, i);
  }
};

LinkedList make_list(string s) {
  LinkedList lst;
  for (auto c : s)
    lst.append(c - '0');
  return lst;
}

void show(const function<ll(LinkedList &, ll)> &f,
          const string &fn,
          const vector<pls> &v) {
  printf("# %s\n", fn.c_str());
  for (auto p : v) {
    ll k = p.first;
    LinkedList lst = make_list(p.second);
    printf(
        "the last %lld th of %s: %lld\n", k, lst.to_str().c_str(), f(lst, k));
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/2_02.txt");
  ll n;
  ifs >> n;
  vector<pls> v(n);
  for (ll i = 0; i < n; ++i) {
    ll k;
    string s;
    ifs >> k >> s;
    v[i] = {k, s};
  }

  show([](LinkedList &lst, ll k) { return lst.last_kth1(k); }, "last_kth1", v);
  show([](LinkedList &lst, ll k) { return lst.last_kth2(k); }, "last_kth2", v);
  show([](LinkedList &lst, ll k) { return lst.last_kth3(k); }, "last_kth3", v);
}
