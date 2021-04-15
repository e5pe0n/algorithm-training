// https://www.geeksforgeeks.org/data-structures/linked-list/
#include <cassert>
#include <fstream>
#include <functional>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct Node {
  ll data;
  Node *next;
};

struct Res {
  Node *node;
  bool res;
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

  bool is_palindrome1() {
    Node *cur = head;
    LinkedList other;
    while (cur != nullptr) {
      other.push(cur->data);
      cur = cur->next;
    }
    Node *cur2 = other.head;
    cur = head;
    while (cur != nullptr) {
      if (cur->data != cur2->data) return false;
      cur = cur->next;
      cur2 = cur2->next;
    }
    return true;
  }

  Node *_is_padlindrom2(Node *cur, bool &res) {
    if (cur == nullptr) return head;
    Node *cur2 = _is_padlindrom2(cur->next, res);
    res &= cur->data == cur2->data;
    return cur2->next;
  }

  bool is_palindrome2() {
    bool res = true;
    _is_padlindrom2(head, res);
    return res;
  }

  bool is_palindrome3() {
    stack<ll> s;
    Node *cur = head;
    while (cur != nullptr) {
      s.push(cur->data);
      cur = cur->next;
    }
    cur = head;
    while (s.size()) {
      ll d = s.top();
      s.pop();
      if (d != cur->data) return false;
      cur = cur->next;
    }
    return true;
  }

  Node *_is_palidrome4(Node *cur, ll i, ll len, bool &res) {
    if (i <= 0) return len % 2 == 0 ? cur : cur->next;
    Node *cur2 = _is_palidrome4(cur->next, i - 1, len, res);
    res &= cur->data == cur2->data;
    return cur2->next;
  }

  bool is_palindrome4() {
    bool res = true;
    ll len = length();
    _is_palidrome4(head, len / 2, len, res);
    return res;
  }

  Res _is_palindrome5(Node *cur) {
    if (cur == nullptr) return Res{head, true};
    Res res = _is_palindrome5(cur->next);
    Node *node = res.node;
    bool r = res.res;
    return Res{node->next, r && cur->data == node->data};
  }

  bool is_palindrome5() {
    return _is_palindrome5(head).res;
  }

  bool is_palindrome6() {
    Node *fast = head, *slow = head;
    stack<ll> s;
    while (fast != nullptr && fast->next != nullptr) {
      s.push(slow->data);
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast != nullptr) { // odd length case
      slow = slow->next;
    }
    while (slow != nullptr) {
      ll t = s.top();
      s.pop();
      if (t != slow->data) return false;
      slow = slow->next;
    }
    return true;
  }

  Res _is_palindrome7(Node *cur, ll len) {
    if (cur == nullptr || len <= 0) { // even length case
      return Res{cur, true};
    } else if (len == 1) { // odd length case
      return Res{cur->next, true};
    }

    Res res = _is_palindrome7(cur->next, len - 2);

    if (!res.res || res.node == nullptr) return res;

    return Res{res.node->next, res.res && cur->data == res.node->data};
  }

  bool is_palindrome7() {
    Res res = _is_palindrome7(head, length());
    return res.res;
  }
};

LinkedList make_list(const string &s) {
  LinkedList lst;
  for (auto c : s)
    lst.append(c);
  return lst;
}

void run(const function<bool(LinkedList &)> &f,
         const string &fn,
         const vector<string> &vs) {
  printf("# %s\n", fn.c_str());
  for (auto s : vs) {
    LinkedList lst = make_list(s);
    printf("%s is %spalindrome\n", lst.to_str().c_str(), f(lst) ? "" : "not ");
    lst.delete_list();
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/2_06.txt");
  ll n;
  ifs >> n;
  vector<string> vs(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> vs[i];
  }
  run([](LinkedList &lst) { return lst.is_palindrome1(); },
      "is_palindrome1",
      vs);
  run([](LinkedList &lst) { return lst.is_palindrome2(); },
      "is_palindrome2",
      vs);
  run([](LinkedList &lst) { return lst.is_palindrome3(); },
      "is_palindrome3",
      vs);
  run([](LinkedList &lst) { return lst.is_palindrome4(); },
      "is_palindrome4",
      vs);
  run([](LinkedList &lst) { return lst.is_palindrome5(); },
      "is_palindrome5",
      vs);
  run([](LinkedList &lst) { return lst.is_palindrome6(); },
      "is_palindrome6",
      vs);
  run([](LinkedList &lst) { return lst.is_palindrome7(); },
      "is_palindrome7",
      vs);
}