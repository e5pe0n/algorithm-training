// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
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

int main() {
  LinkedList lst;
  lst.append(6);
  lst.push(7);
  lst.push(1);
  lst.append(4);
  lst.insert_after(lst.head->next, 8);
  puts(lst.to_str().c_str());
  lst.delete_node(1);
  puts(lst.to_str().c_str());
  lst.delete_node_by_pos(2);
  puts(lst.to_str().c_str());
  printf("%lld\n", lst.length());
  printf("%s\n", lst.search(8) ? "true" : "false");
  printf("%lld\n", lst.get(2));
}