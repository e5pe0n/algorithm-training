// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
#include <fstream>
#include <functional>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<vector<ll>, vector<ll>> pvv;

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

LinkedList make_list(const vector<ll> &v) {
  LinkedList lst;
  for (auto _v : v) {
    lst.append(_v);
  }
  return lst;
}

LinkedList copy(const LinkedList &lst) {
  LinkedList clone;
  Node *cur = lst.head;
  while (cur != nullptr) {
    clone.append(cur->data);
    cur = cur->next;
  }
  return clone;
}

bool _sum1(Node *cur1, Node *cur2, LinkedList &res) {
  if (cur1 == nullptr && cur2 == nullptr) return 0;
  ll t = cur1->data + cur2->data + _sum1(cur1->next, cur2->next, res);
  res.push(t % 10);
  return t >= 10;
}

LinkedList sum1(const LinkedList &lst1, const LinkedList &lst2) {
  LinkedList clone1 = copy(lst1);
  LinkedList clone2 = copy(lst2);
  LinkedList res;
  Node *cur1 = clone1.head;
  Node *cur2 = clone2.head;
  while (cur1 != nullptr && cur2 != nullptr) {
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  while (cur1 != nullptr) {
    clone2.push(0);
    cur1 = cur1->next;
  }
  while (cur2 != nullptr) {
    clone1.push(0);
    cur2 = cur2->next;
  }
  bool carry = _sum1(clone1.head, clone2.head, res);
  if (carry) res.push(carry);
  return res;
}

struct PartialSum {
  Node *sum = nullptr;
  ll carry = 0;
};

void pad_list(LinkedList &lst, ll len) {
  while (len--) {
    lst.push(0);
  }
}

Node *insert_before(Node *node, ll data) {
  Node *new_node = new Node;
  new_node->data = data;
  if (node != nullptr) new_node->next = node;
  return new_node;
}

PartialSum add_list_helper(Node *cur1, Node *cur2) {
  if (cur1 == nullptr && cur2 == nullptr) {
    PartialSum s;
    return s;
  }

  PartialSum s = add_list_helper(cur1->next, cur2->next);
  ll val = s.carry + cur1->data + cur2->data;

  Node *full_res = insert_before(s.sum, val % 10);

  s.sum = full_res;
  s.carry = val / 10;
  return s;
}

LinkedList sum2(const LinkedList &lst1, const LinkedList &lst2) {
  LinkedList clone1 = copy(lst1);
  LinkedList clone2 = copy(lst2);

  ll len1 = clone1.length();
  ll len2 = clone2.length();
  if (len1 < len2) {
    pad_list(clone1, len2 - len1);
  } else {
    pad_list(clone2, len1 - len2);
  }

  PartialSum s = add_list_helper(clone1.head, clone2.head);

  LinkedList res;
  if (s.carry) {
    res.head = insert_before(s.sum, s.carry);
  } else {
    res.head = s.sum;
  }
  return res;
}

void run(const function<LinkedList(LinkedList &, LinkedList &)> &f,
         const string &fn,
         const vector<pvv> &ps) {
  printf("# %s\n", fn.c_str());
  for (auto [v1, v2] : ps) {
    LinkedList lst1 = make_list(v1);
    LinkedList lst2 = make_list(v2);
    LinkedList res = f(lst1, lst2);
    printf("%s + %s = %s\n",
           lst1.to_str().c_str(),
           lst2.to_str().c_str(),
           res.to_str().c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/2_05_2.txt");
  ll n;
  ifs >> n;
  vector<pvv> ps(n);
  for (ll i = 0; i < n; ++i) {
    ll m1, m2;
    ifs >> m1 >> m2;
    vector<ll> v1(m1), v2(m2);
    for (ll i = 0; i < m1; ++i) {
      ifs >> v1[i];
    }
    for (ll i = 0; i < m2; ++i) {
      ifs >> v2[i];
    }
    ps[i] = {v1, v2};
  }
  run(sum1, "sum1", ps);
  run(sum2, "sum2", ps);
}

// # sum1
// [6 1 7] + [2 9 5] = [9 1 2]
// [6 1 7] + [3 9 5] = [1 0 1 2]
// [9 7] + [9 9 0 3] = [1 0 0 0 0]
// [8 7 9] + [5 8 6] = [1 4 6 5]

// # sum2
// [6 1 7] + [2 9 5] = [9 1 2]
// [6 1 7] + [3 9 5] = [1 0 1 2]
// [9 7] + [9 9 0 3] = [1 0 0 0 0]
// [8 7 9] + [5 8 6] = [1 4 6 5]
