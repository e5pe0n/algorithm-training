#include <memory>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

struct Node {
  int n;
  bool leaf;
  int *key;
  shared_ptr<Node> c[4];
};

void disk_read(shared_ptr<Node> x) {}

void disk_write(shared_ptr<Node> x) {}

struct Tree {
  shared_ptr<Node> root = nullptr;
  int t = 2;

  shared_ptr<Node> allocate_node() {
    auto x = shared_ptr<Node>();
    return x;
  }

  void b_tree_create() {
    auto x = allocate_node();
    x->leaf = true;
    x->n = 0;
    disk_write(x);
    root = x;
  }

  pair<shared_ptr<Node>, int> b_tree_serach(shared_ptr<Node> x, int k) {
    int i = 0;
    while (i < x->n && k > x->key[i]) {
      ++i;
    }
    if (i <= x->n && k == x->key[i]) {
      return make_pair(x, i);
    } else if (x->leaf) {
      return make_pair(nullptr, -1);
    } else {
      disk_read(x->c[i]);
      return b_tree_serach(x->c[i], k);
    }
  }

  void b_tree_split_child(shared_ptr<Node> x, int i) {
    auto z = allocate_node();
    auto y = x->c[i];
    z->leaf = y->leaf;
    z->n = y->n / 2; // z->n = t - 1;
    for (int j = 0; j < z->n; ++j) {
      z->key[j] = y->key[j + z->n + 1];
    }
    if (!y->leaf) {
      for (int j = 0; j <= z->n; ++j) {
        z->c[j] = y->c[j + z->n + 1];
      }
    }
    y->n = y->n / 2 + y->n % 2 - 1;

    for (int j = x->n; j >= i + 1; --j) {
      x->c[j + 1] = x->c[j];
    }
    x->c[i + 1] = z;

    for (int j = x->n - 1; j >= i; --j) {
      x->key[j + 1] = x->key[j];
    }
    x->key[i] = y->key[y->n];
    ++x->n;
    disk_write(y);
    disk_write(z);
    disk_write(x);
  }

  void b_tree_insert_nonfull(shared_ptr<Node> x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
      while (i >= 0 && k < x->key[i]) {
        x->key[i + 1] = x->key[i];
        --i;
      }
      x->key[i + 1] = k;
      ++x->n;
      disk_write(x);
    } else {
      while (i >= 0 && k < x->key[i]) {
        --i;
      }
      ++i;
      disk_read(x->c[i]);
      if (x->c[i]->n == 2 * t - 1) {
        b_tree_split_child(x, i);
        if (k > x->key[i]) {
          ++i;
        }
      }
      b_tree_insert_nonfull(x->c[i], k);
    }
  }

  void b_tree_insert(int k) {
    auto r = root;
    if (r->n == 2 * t - 1) {
      auto s = allocate_node();
      root = s;
      s->leaf = false;
      s->n = 0;
      s->c[0] = r;
      b_tree_split_child(s, 0);
      b_tree_insert_nonfull(s, k);
    } else {
      b_tree_insert_nonfull(r, k);
    }
  }

  void b_tree_delete(shared_ptr<Node> x, int k) {
    int idx = 0;
    while (idx < x->n && k > x->key[idx])
      ++idx;
    if (idx < x->n && k == x->key[idx]) {
      if (x->leaf) {
        for (int i = idx; i < x->n; ++i) {
          x->key[i] = x->key[i + 1];
        }
        return;
      } else {
        if (idx == x->n)
          --idx;
        shared_ptr<Node> y = x->c[idx];
        shared_ptr<Node> z = x->c[idx + 1];
        if (y->n >= t) {
          int _k = y->key[y->n - 1];
          x->key[idx] = _k;
          b_tree_delete(y, _k);
        } else if (z->n >= t) {
          int _k = z->key[0];
          x->key[idx] = _k;
          b_tree_delete(z, _k);
        } else {
          y->key[y->n] = x->key[idx];
          for (int i = 0; i < z->n; ++i) {
            y->key[y->n + 1 + i] = z->key[i];
            y->c[y->n + 1 + i] = z->c[i];
          }
          y->c[y->n + 1 + z->n] = z->c[z->n];
          y->n += 1 + z->n;
          for (int i = idx; i < x->n - 1; ++i) {
            x->key[i] = x->key[i + 1];
          }
          for (int i = idx + 1; i < x->n; ++i) {
            x->c[i] = x->c[i + 1];
          }
          b_tree_delete(y, k);
        }
      }
    } else {
      if (x->c[idx]->n <= t - 1) {
        if (idx > 0 && x->c[idx - 1]->n >= t) {
          for (int j = x->c[idx]->n - 1; j > 0; --j) {
            x->c[idx]->key[j + 1] = x->c[idx]->key[j];
          }
          x->c[idx]->key[0] = x->key[idx];
          x->key[idx] = x->c[idx - 1]->key[x->c[idx - 1]->n - 1];
          for (int j = x->c[idx]->n; j > 0; --j) {
            x->c[idx]->c[j + 1] = x->c[idx]->c[j];
          }
          x->c[idx]->c[0] = x->c[idx - 1]->c[x->c[idx - 1]->n];
          --x->c[idx - 1]->n;
          ++x->c[idx]->n;
          b_tree_delete(x->c[idx], k);
        } else if (idx < x->n && x->c[idx + 1]->n >= t) {
          x->c[idx]->key[x->c[idx]->n] = x->key[idx];
          x->key[idx] = x->c[idx + 1]->key[0];
          for (int j = 1; j < x->c[idx + 1]->n; ++j) {
            x->c[idx + 1]->key[j - 1] = x->c[idx + 1]->key[j];
          }
          x->c[idx]->c[x->c[idx]->n + 1] = x->c[idx + 1]->c[0];
          for (int j = x->c[idx + 1]->n; j > 0; --j) {
            x->c[idx + 1]->c[j - 1] = x->c[idx + 1]->c[j];
          }
          --x->c[idx + 1]->n;
          ++x->c[idx]->n;
          b_tree_delete(x->c[idx], k);
        } else {
          if (idx > 0) {
            x->c[idx - 1]->key[x->c[idx - 1]->n] = x->key[idx - 1];
            for (int j = 0; j < x->c[idx]->n; ++j) {
              x->c[idx - 1]->key[x->c[idx - 1]->n + 1 + j] = x->c[idx]->key[j];
              x->c[idx - 1]->c[x->c[idx - 1]->n + 1 + j] = x->c[idx]->c[j];
            }
            x->c[idx - 1]->c[x->c[idx - 1]->n + 1 + x->c[idx]->n] = x->c[idx]->c[x->c[idx]->n];
            x->c[idx - 1]->n += 1 + x->c[idx]->n;
            for (int j = idx - 1; j < x->n - 1; ++j) {
              x->key[j] = x->key[j + 1];
              x->c[j] = x->c[j + 1];
            }
            x->c[x->n - 1] = x->c[x->n];
            --x->n;
            b_tree_delete(x->c[idx - 1], k);
          } else {
            x->c[idx]->key[x->c[idx]->n] = x->key[idx];
            for (int j = 0; j < x->c[idx + 1]->n; ++j) {
              x->c[idx]->key[x->c[idx]->n + 1 + j] = x->c[idx + 1]->key[j];
              x->c[idx]->c[x->c[idx]->n + 1 + j] = x->c[idx + 1]->c[j];
            }
            x->c[idx]->c[x->c[idx]->n + 1 + x->c[idx + 1]->n] = x->c[idx + 1]->c[x->c[idx + 1]->n];
            x->c[idx]->n += 1 + x->c[idx + 1]->n;
            for (int j = idx; j < x->n - 1; ++j) {
              x->key[j] = x->key[j + 1];
              x->c[j] = x->c[j + 1];
            }
            x->c[x->n - 1] = x->c[x->n];
            --x->n;
            b_tree_delete(x->c[idx], k);
          }
        }
      }
    }
  }
};

int main() {}