// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
#include <fstream>
#include <functional>
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

  Node *get_ptr(ll key) {
    Node *cur = head;
    while (cur != nullptr) {
      if (cur->data == key) return cur;
      cur = cur->next;
    }
    return cur;
  }
};

LinkedList make_list(string s) {
  LinkedList lst;
  for (auto c : s)
    lst.append(c);
  return lst;
}

void del_md_node1(Node *md) {
  md->data = md->next->data;
  Node *tmp = md->next;
  md->next = md->next->next;
  delete tmp;
}

bool del_md_node2(Node *md) {
  if (md == nullptr || md->next == nullptr) return false;
  Node *tmp = md->next;
  md->data = md->next->data;
  md->next = md->next->next;
  delete tmp;
  return true;
}

void run1(const function<void(Node *)> &f,
          const string &fn,
          const vector<pls> &ps) {
  printf("# %s\n", fn.c_str());
  for (auto p : ps) {
    ll k = p.first;
    string s = p.second;
    LinkedList lst = make_list(s);
    string before = lst.to_str();
    f(lst.get_ptr(k));
    string after = lst.to_str();
    printf("%lld: %s -> %s\n", k, before.c_str(), after.c_str());
  }
  puts("");
}

void run2(const function<bool(Node *)> &f,
          const string &fn,
          const vector<pls> &ps) {
  printf("# %s\n", fn.c_str());
  for (auto p : ps) {
    ll k = p.first;
    string s = p.second;
    LinkedList lst = make_list(s);
    string before = lst.to_str();
    f(lst.get_ptr(k));
    string after = lst.to_str();
    printf("%lld: %s -> %s\n", k, before.c_str(), after.c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/2_03.txt");
  ll n;
  ifs >> n;
  vector<pls> ps(n);
  for (ll i = 0; i < n; ++i) {
    char k;
    string s;
    ifs >> k >> s;
    ps[i] = {k, s};
  }

  run1(del_md_node1, "del_md_node1", ps);
  run2(del_md_node2, "del_md_node2", ps);
}