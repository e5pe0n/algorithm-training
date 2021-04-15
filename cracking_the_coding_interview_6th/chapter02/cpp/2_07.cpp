// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
#include <fstream>
#include <functional>
#include <string>
using namespace std;
typedef long long ll;

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
};

LinkedList copy(const LinkedList &lst) {
  LinkedList clone;
  Node *cur = lst.head;
  while (cur != nullptr) {
    clone.append(cur->data);
    cur = cur->next;
  }
  return clone;
}

Node *forward(Node *node, ll cnt) {
  while (cnt--) {
    assert(node != nullptr);
    node = node->next;
  }
  return node;
}

Node *get_intersection1(LinkedList &lst1, LinkedList &lst2) {
  ll len1 = lst1.length();
  ll len2 = lst2.length();

  Node *cur1 = lst1.head;
  Node *cur2 = lst2.head;
  if (len1 < len2) {
    cur2 = forward(cur2, len2 - len1);
  } else {
    cur1 = forward(cur1, len1 - len2);
  }
  while (cur1 != cur2) {
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  return cur1;
}

pair<LinkedList, LinkedList> make_list() {
  LinkedList lst1, lst2;
  for (ll i = 10; i < 20; ++i) {
    lst1.append(i);
  }
  for (ll i = 20; i < 23; ++i) {
    lst2.append(i);
  }
  Node *cur1 = lst1.head;
  for (ll _ = 0; _ < 5; ++_) {
    cur1 = cur1->next;
  }
  Node *cur2 = lst2.head;
  while (cur2->next != nullptr) {
    cur2 = cur2->next;
  }
  cur2->next = cur1;
  return {lst1, lst2};
}

void run(const function<Node *(LinkedList &, LinkedList &)> &f,
         const string &fn) {
  printf("# %s\n", fn.c_str());
  auto [lst1, lst2] = make_list();
  printf("lst1: %s\n", lst1.to_str().c_str());
  printf("lst2: %s\n", lst2.to_str().c_str());
  Node *res = f(lst1, lst2);
  printf("intersection: %lld\n", res->data);
  puts("");
  // lst1.delete_list();
  // lst2.delete_list();
}

int main() {
  run(get_intersection1, "get_intersection1");
}

// # get_intersection1
// lst1: [10 11 12 13 14 15 16 17 18 19]
// lst2: [20 21 22 15 16 17 18 19]
// intersection: 15
