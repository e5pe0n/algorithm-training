// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
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

Node *detect_loop1(LinkedList &lst) {
  if (lst.head == nullptr || lst.head->next == nullptr) return nullptr;
  Node *slow = lst.head;
  Node *fast = slow->next;
  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) return nullptr;
    slow = slow->next;
    fast = fast->next->next;
  }

  ll loop_len = 1;
  fast = fast->next;
  while (slow != fast) {
    fast = fast->next;
    ++loop_len;
  }

  slow = lst.head;
  fast = slow;
  while (loop_len--) {
    fast = fast->next;
  }
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

Node *detect_loop2(LinkedList &lst) {
  Node *slow = lst.head;
  Node *fast = lst.head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
  }

  if (fast == nullptr || fast->next == nullptr) return nullptr;

  slow = lst.head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return fast;
}

LinkedList make_list() {
  LinkedList lst;
  for (ll i = 0; i < 10; ++i) {
    lst.append(i);
  }
  return lst;
}

LinkedList make_loop_list1() {
  // 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
  //                  -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
  //                  -> ...
  LinkedList lst;
  lst.head = new Node;
  lst.head->data = 0;
  lst.head->next = nullptr;
  Node *cur = lst.head;
  Node *mid;
  for (ll i = 1; i < 10; ++i) {
    if (i == 5) mid = cur;
    Node *new_node = new Node;
    new_node->data = i;
    new_node->next = nullptr;
    cur->next = new_node;
    cur = cur->next;
  }
  cur->next = mid;
  return lst;
}

LinkedList make_loop_list2() {
  // 0 -> 0 -> 0 -> 0 -> ...
  LinkedList lst;
  lst.head = new Node;
  lst.head->data = 0;
  lst.head->next = lst.head;
  return lst;
}

LinkedList make_loop_list3() {
  // 0 -> 1 -> 0 -> 1 -> 0 -> 1 -> ...
  LinkedList lst;
  lst.head = new Node;
  lst.head->data = 0;
  Node *new_node = new Node;
  new_node->data = 1;
  new_node->next = lst.head;
  lst.head->next = new_node;
  return lst;
}

struct Res {
  string detected;
  ll data;
};

Res parse_res(Node *res) {
  if (res == nullptr)
    return Res{"false", -1};
  else
    return Res{"true", res->data};
}

void run(const function<Node *(LinkedList &)> &f, const string &fn) {
  printf("# %s\n", fn.c_str());
  LinkedList lst = make_list();
  Res res = parse_res(f(lst));
  printf(
      "'lst' has loop: %s, start at: %lld\n", res.detected.c_str(), res.data);
  lst.delete_list();

  LinkedList loop_lst1 = make_loop_list1();
  Res res1 = parse_res(f(loop_lst1));
  printf("'loop_lst1' has loop: %s, start at: %lld\n",
         res1.detected.c_str(),
         res1.data);
  // loop_lst1.delete_list();

  LinkedList loop_lst2 = make_loop_list2();
  Res res2 = parse_res(f(loop_lst2));
  printf("'loop_lst2' has loop: %s, start at: %lld\n",
         res2.detected.c_str(),
         res2.data);
  // loop_lst2.delete_list();

  LinkedList loop_lst3 = make_loop_list3();
  Res res3 = parse_res(f(loop_lst3));
  printf("'loop_lst3' has loop: %s, start at: %lld\n",
         res3.detected.c_str(),
         res3.data);
  // loop_lst3.delete_list();
  puts("");
}

int main() {
  run(detect_loop1, "detect_loop1");
  run(detect_loop2, "detect_loop2");
}

// # detect_loop1
// 'lst' has loop: false, start at: -1
// 'loop_lst1' has loop: true, start at: 4
// 'loop_lst2' has loop: true, start at: 0
// 'loop_lst3' has loop: true, start at: 0

// # detect_loop2
// 'lst' has loop: false, start at: -1
// 'loop_lst1' has loop: true, start at: 4
// 'loop_lst2' has loop: true, start at: 0
// 'loop_lst3' has loop: true, start at: 0
