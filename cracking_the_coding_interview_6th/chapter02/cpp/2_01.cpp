#include <cassert>
#include <fstream>
#include <functional>
#include <set>
#include <string>
#include <vector>
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
    string res;
    while (node != nullptr) {
      res += to_string(node->data);
      res += " ";
      node = node->next;
    }
    if (res.size()) res.pop_back();
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

  void drop_dup1() {
    // time O(n^2), space O(1)
    Node *src = head;
    if (src == nullptr || src->next == nullptr) return;

    while (src != nullptr) {
      Node *prev = src;
      Node *seeker = src->next;
      while (seeker != nullptr) {
        if (seeker->data == src->data) {
          Node *tmp = seeker;
          prev->next = seeker->next;
          seeker = prev->next;
          delete tmp;
        } else {
          prev = seeker;
          seeker = seeker->next;
        }
      }
      src = src->next;
    }
  }

  void drop_dup2() {
    // time O(n), space O(n)
    Node *prev = nullptr;
    Node *cur = head;
    set<ll> st;
    while (cur != nullptr) {
      if (st.count(cur->data)) {
        Node *tmp = cur;
        prev->next = cur->next;
        cur = cur->next;
        delete tmp;
      } else {
        st.insert(cur->data);
        prev = cur;
        cur = cur->next;
      }
    }
  }
};

LinkedList make_list(string s) {
  LinkedList lst;
  for (auto c : s)
    lst.append(c);
  return lst;
}

void show(const function<void(LinkedList &)> &f,
          const string &fn,
          const vector<string> &vs) {
  printf("# %s\n", fn.c_str());
  for (auto s : vs) {
    LinkedList lst = make_list(s);
    string before = lst.to_str();
    f(lst);
    string after = lst.to_str();
    printf("%s -> %s\n", before.c_str(), after.c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/2_01.txt");
  ll n;
  ifs >> n;
  vector<string> vs(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> vs[i];
  }

  show([](LinkedList &lst) { lst.drop_dup1(); }, "drop_dup1", vs);
  show([](LinkedList &lst) { lst.drop_dup2(); }, "drop_dup2", vs);
}

// # drop_dup1
// 70 79 76 76 79 87 85 80 -> 70 79 76 87 85 80
// 84 69 83 84 67 65 83 69 83 -> 84 69 83 67 65
// 65 65 65 65 65 -> 65

// # drop_dup2
// 70 79 76 76 79 87 85 80 -> 70 79 76 87 85 80
// 84 69 83 84 67 65 83 69 83 -> 84 69 83 67 65
// 65 65 65 65 65 -> 65
