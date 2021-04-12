// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
#include <fstream>
#include <functional>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, vector<ll>> plv;

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

LinkedList partition1(const LinkedList &lst, const ll &x) {
  // stable i.e. keeps the relative order in each partition
  LinkedList clone = copy(lst);
  Node *sep = new Node;
  sep->data = -1;
  sep->next = clone.head;
  clone.head = sep;
  Node *runner = sep->next;
  Node *prev = sep;
  while (runner != nullptr) {
    if (runner->data >= x) {
      prev = runner;
      runner = runner->next;
    } else {
      Node *new_sep = new Node;
      new_sep->data = sep->data;
      new_sep->next = sep->next;
      sep->next = new_sep;
      sep->data = runner->data;
      sep = new_sep;
      while (prev->next != runner) {
        prev = prev->next;
      }
      if (runner->next != nullptr) {
        Node *tmp = runner->next;
        runner->data = runner->next->data;
        runner->next = runner->next->next;
        delete tmp;
      } else {
        Node *tmp = runner;
        prev->next = nullptr;
        runner = nullptr;
        delete tmp;
      }
    }
  }
  return clone;
}

LinkedList partition2(const LinkedList &lst, const ll &x) {
  // not stable i.e.  not consider the relative order in each partition
  LinkedList clone = copy(lst);
  Node *sep = new Node;
  sep->data = -1;
  sep->next = clone.head;
  clone.head = sep;
  Node *runner = sep->next;
  Node *fst_greater = nullptr;
  while (runner != nullptr) {
    if (runner->data >= x) {
      if (fst_greater == nullptr) fst_greater = runner;
    } else {
      if (fst_greater != nullptr) {
        swap(fst_greater->data, runner->data);
        swap(sep->data, fst_greater->data);
        fst_greater = fst_greater->next;
        sep = sep->next;
      } else {
        swap(sep->data, runner->data);
        sep = sep->next;
      }
    }
    runner = runner->next;
  }
  return clone;
}

LinkedList partition3(const LinkedList &lst, const ll &x) {
  // stable
  LinkedList clone = copy(lst);
  Node *before_start = nullptr;
  Node *before_end = nullptr;
  Node *after_start = nullptr;
  Node *after_end = nullptr;

  Node *cur = clone.head;
  while (cur != nullptr) {
    Node *next = cur->next;
    cur->next = nullptr;
    if (cur->data < x) {
      if (before_start == nullptr) {
        before_start = cur;
        before_end = before_start;
      } else {
        before_end->next = cur;
        before_end = cur;
      }
    } else {
      if (after_start == nullptr) {
        after_start = cur;
        after_end = after_start;
      } else {
        after_end->next = cur;
        after_end = cur;
      }
    }
    cur = next;
  }

  LinkedList res;
  Node *sep = new Node;
  sep->data = -1;
  sep->next = after_start;
  if (before_start == nullptr) {
    res.head = sep;
  } else {
    before_end->next = sep;
    res.head = before_start;
  }
  return res;
}

LinkedList partition4(const LinkedList &lst, const ll &x) {
  // unstable
  LinkedList clone = copy(lst);
  Node *cur = lst.head;
  Node *sep = new Node;
  sep->data = -1;
  sep->next = cur;
  Node *head = sep;
  Node *tail = sep;

  while (cur != nullptr) {
    Node *next = cur->next;
    if (cur->data < x) {
      cur->next = head;
      head = cur;
    } else {
      tail->next = cur;
      tail = cur;
    }
    cur = next;
  }
  tail->next = nullptr;

  LinkedList res;
  res.head = head;
  return res;
}

LinkedList make_list(vector<ll> v) {
  LinkedList lst;
  for (auto _v : v) {
    lst.append(_v);
  }
  return lst;
}

void run(const function<LinkedList(LinkedList &, ll)> &f,
         const string &fn,
         const vector<plv> &ps) {
  printf("# %s\n", fn.c_str());
  for (auto p : ps) {
    ll x = p.first;
    vector<ll> v = p.second;
    LinkedList before = make_list(v);
    LinkedList after = f(before, x);
    printf(
        "%lld: %s -> %s\n", x, before.to_str().c_str(), after.to_str().c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/2_04.txt");
  ll n;
  ifs >> n;
  vector<plv> ps(n);
  for (ll i = 0; i < n; ++i) {
    ll m, x;
    ifs >> m >> x;
    vector<ll> v(m);
    for (ll j = 0; j < m; ++j) {
      ifs >> v[j];
    }
    ps[i] = {x, v};
  }

  run(partition1, "partition1", ps);
  run(partition2, "partition2", ps);
  run(partition3, "partition3", ps);
  run(partition4, "partition4", ps);
}

// # partition1
// 5: [3 5 8 5 10 2 1] -> [3 2 1 -1 5 8 5 10]
// 3: [3 5 8 5 10 2 1] -> [2 1 -1 3 5 8 5 10]
// 0: [3 5 8 5 10 2 1] -> [-1 3 5 8 5 10 2 1]
// 11: [3 5 8 5 10 2 1] -> [3 5 8 5 10 2 1 -1]
// 5: [5 5 5 5 5] -> [-1 5 5 5 5 5]
