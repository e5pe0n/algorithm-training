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

LinkedList sum1(const LinkedList &lst1, const LinkedList &lst2) {
  LinkedList clone1 = copy(lst1);
  LinkedList clone2 = copy(lst2);
  LinkedList res;
  Node *cur1 = clone1.head;
  Node *cur2 = clone2.head;
  bool carry = 0;
  while (cur1 != nullptr && cur2 != nullptr) {
    ll t = cur1->data + cur2->data + carry;
    carry = t >= 10;
    res.append(t % 10);
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  while (cur1 != nullptr) {
    ll t = cur1->data + carry;
    carry = t >= 10;
    res.append(t % 10);
    cur1 = cur1->next;
  }
  while (cur2 != nullptr) {
    ll t = cur2->data + carry;
    carry = t >= 10;
    res.append(t % 10);
    cur2 = cur2->next;
  }
  if (carry) res.append(1);
  return res;
}

Node *_sum2(Node *cur1, Node *cur2, bool carry) {
  if (cur1 == nullptr && cur2 == nullptr) {
    Node *new_head = nullptr;
    if (carry) {
      new_head = new Node;
      new_head->data = 1;
      new_head->next = nullptr;
    }
    return new_head;
  }
  ll data1 = cur1 == nullptr ? 0 : cur1->data;
  ll data2 = cur2 == nullptr ? 0 : cur2->data;
  ll t = data1 + data2 + carry;
  Node *new_head = new Node;
  new_head->data = t % 10;
  new_head->next = _sum2(cur1 == nullptr ? nullptr : cur1->next,
                         cur2 == nullptr ? nullptr : cur2->next,
                         t >= 10);
  return new_head;
}

LinkedList sum2(const LinkedList &lst1, const LinkedList &lst2) {
  LinkedList clone1 = copy(lst1);
  LinkedList clone2 = copy(lst2);
  LinkedList res;
  res.head = _sum2(clone1.head, clone2.head, 0);
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
  ifstream ifs("../testcases/2_05_1.txt");
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
// [7 1 6] + [5 9 2] = [2 1 9]
// [7 1 6] + [5 9 3] = [2 1 0 1]
// [7 9] + [3 0 9 9] = [0 0 0 0 1]
// [9 7 8] + [6 8 5] = [5 6 4 1]

// # sum2
// [7 1 6] + [5 9 2] = [2 1 9]
// [7 1 6] + [5 9 3] = [2 1 0 1]
// [7 9] + [3 0 9 9] = [0 0 0 0 1]
// [9 7 8] + [6 8 5] = [5 6 4 1]