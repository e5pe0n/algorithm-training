#include <iostream>
#include <string>

using namespace std;

struct _List {
  struct _El {
    int key;
    _El *prv = nullptr;
    _El *nxt = nullptr;

    _El(int key) : key(key) {
      prv = this;
      nxt = this;
    }

    string _str() {
      string prv_key_s = "null";
      if (prv != nullptr)
        prv_key_s = to_string(prv->key);

      string nxt_key_s = "null";
      if (nxt != nullptr)
        nxt_key_s = to_string(nxt->key);

      return "(key: " + to_string(key) + " prv: " + prv_key_s + " nxt: " + nxt_key_s + ")";
    }
  };

  _El nil = _El(-1);

  _List(int *initializer, int initializer_size) {
    for (int i = 0; i < initializer_size; ++i) {
      list_insert(i);
    }
  }
  ~_List() {
    while (nil.nxt != &nil) {
      _list_delete(nil.nxt);
    }
  }

  string _str() {
    string s = "[";
    _El *x = nil.nxt;
    while (x != &nil) {
      s += to_string(x->key);
      s += ", ";
      x = x->nxt;
    }
    return s += "]";
  }

  void _list_insert(_El *x) {
    x->nxt = nil.nxt;
    nil.nxt->prv = x;
    nil.nxt = x;
    x->prv = &nil;
  }

  void list_insert(int k) {
    _El *x = new _El(k);
    _list_insert(x);
  }

  _El *list_search(int k) {
    _El *x = nil.nxt;
    while (x != &nil && x->key != k) {
      x = x->nxt;
    }
    return x;
  }

  string list_search_str(int k) {
    string res_str = "null";
    _El *res = list_search(k);
    if (res != &nil)
      res_str = res->_str();
    return res_str;
  }

  void _list_delete(_El *x) {
    x->prv->nxt = x->nxt;
    x->nxt->prv = x->prv;
  }

  void list_delete(int k) {
    _El *x = list_search(k);
    if (x != &nil) {
      _list_delete(x);
      delete x;
    }
  }
};

int main() {
  int initializer[] = {0, 1, 2};
  _List _list(initializer, int(sizeof(initializer) / sizeof(initializer[0])));

  cout << _list._str() << "\n";
  _list.list_insert(4);
  cout << _list._str() << "\n";
  cout << "_list.list_search(2): " << _list.list_search_str(2) << "\n";
  cout << "_list.list_search(5): " << _list.list_search_str(5) << "\n";
  _list.list_delete(5);
  cout << _list._str() << "\n";
  _list.list_delete(4);
  cout << _list._str() << "\n";
  _list.list_delete(1);
  cout << _list._str() << "\n";
  cout << "_list.list_search(1): " << _list.list_search_str(1) << endl;
}