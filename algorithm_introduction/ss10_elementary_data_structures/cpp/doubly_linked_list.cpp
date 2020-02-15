#include <iostream>
#include <string>

using namespace std;

struct _List {
  struct _El {
    int key;
    _El *prv = nullptr;
    _El *nxt = nullptr;

    _El(int _key) : key(_key) {}

    string _El_str() {
      string prv_key_s = "null";
      if (prv != nullptr) {
        prv_key_s = to_string(prv->key);
      }

      string nxt_key_s = "null";
      if (nxt != nullptr) {
        nxt_key_s = to_string(nxt->key);
      }

      return "key: " + to_string(key) + " prv: " + prv_key_s + " nxt: " + nxt_key_s;
    }
  };

  _El *head = nullptr;

  _List(int *initializer, int initializer_size) {
    for (int i = 0; i < initializer_size; ++i) {
      list_insert(i);
    }
  }

  ~_List() {
    while (head->nxt != nullptr) {
      _list_delete(head->nxt);
    }
  }

  string _List_str() {
    string s = "[";
    _El *x = head;
    while (x != nullptr) {
      s += to_string(x->key);
      s += ", ";
      x = x->nxt;
    }
    return s += "]";
  }

  void _list_insert(_El *x) {
    x->nxt = head;
    if (head != nullptr) {
      head->prv = x;
    }
    head = x;
    x->prv = nullptr;
  }

  void list_insert(int k) {
    _El *x = new _El(k);
    _list_insert(x);
  }

  string list_search_with_null_safe_res(int k) {
    string res_str = "null";
    _El *res = list_search(k);
    if (res != nullptr)
      res_str = res->_El_str();
    return res_str;
  }

  _El *list_search(int k) {
    _El *x = head;
    while (x != nullptr && x->key != k)
      x = x->nxt;
    return x;
  }

  void _list_delete(_El *x) {
    if (x->prv != nullptr) {
      x->prv->nxt = x->nxt;
    } else {
      head = x->nxt;
    }
    if (x->nxt != nullptr) {
      x->nxt->prv = x->prv;
    }
    delete x;
  }

  void list_delete(int k) {
    _El *x = list_search(k);
    if (x != nullptr) {
      _list_delete(x);
    }
  }
};

int main() {
  int initializer[] = {0, 1, 2};
  _List _list(initializer, int(sizeof(initializer) / sizeof(initializer[0])));

  cout << _list._List_str() << "\n";
  _list.list_insert(4);
  cout << "_list.list_search(2): " << _list.list_search_with_null_safe_res(2) << "\n";
  cout << "_list.list_search(5): " << _list.list_search_with_null_safe_res(5) << "\n";
  _list.list_delete(5);
  cout << _list._List_str() << "\n";
  _list.list_delete(4);
  cout << _list._List_str() << "\n";
  _list.list_delete(1);
  cout << _list._List_str() << "\n";
  cout << "_ilst.list_search(1): " << _list.list_search_with_null_safe_res(1) << endl;
}