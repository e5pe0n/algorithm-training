#include <stdio.h>
#include <string>

using namespace std;

enum class Color { BLACK, RED };
struct Node {
  int key;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *p = nullptr;
  Color color = Color::RED; // black: 1, red: 1
  Node(int key, Node *p, Color color) : key(key), p(p), color(color) {}
};

struct Tree {

  Node *root;
  Node *nil = nullptr;

  Tree(Node *root) : root(root) { root->p = nil; }

  Node *tree_minimum(Node *x) {
    while (x->left != nil)
      x = x->left;
    return x;
  }

  void left_rotate(Node *x) {
    Node *y = x->right;

    x->right = y->left;
    if (y->left != nil)
      y->left->p = x;
    y->p = x->p;

    if (x->p == nil)
      root = y;
    else if (x == x->p->left)
      x->p->left = y;
    else
      x->p->right = y;

    y->left = x;
    x->p = y;
  }

  void right_rotate(Node *x) {
    Node *y = x->left;

    x->left = y->right;
    if (y->right != nil)
      y->right->p = x;
    y->p = x->p;

    if (x->p == nil)
      root = y;
    else if (x->p->left)
      x->p->left = y;
    else
      x->p->right = y;

    y->right = x;
    x->p = y;
  }

  void _rb_insert_fixup(Node *z) {
    Node *y = nullptr;
    while (z->p->color == Color::RED) {
      if (z->p == z->p->p->left) {
        y = z->p->p->left;
        if (y->color == Color::RED) {
          z->p->color = Color::BLACK;
          y->color = Color::BLACK;
          z->p->p->color = Color::RED;
          z = z->p->p;
        } else {
          if (z == z->p->right) {
            z = z->p;
            left_rotate(z);
          }
          z->p->color = Color::BLACK;
          z->p->p->color = Color::RED;
          right_rotate(z->p->p);
        }
      } else {
        y = z->p->p->right;
        if (y->color == Color::RED) {
          z->p->color = Color::BLACK;
          y->color = Color::BLACK;
          z->p->p->color = Color::RED;
          z = z->p->p;
        } else {
          if (z == z->p->left) {
            z = z->p;
            right_rotate(z);
          }
          z->p->color = Color::BLACK;
          z->p->p->color = Color::RED;
          left_rotate(z->p->p);
        }
      }
      root->color = Color::BLACK;
    }
  }

  void rb_insert(Node *z) {
    Node *y = nil;
    Node *x = root;
    while (x != nil) {
      y = x;
      if (z->key < x->key)
        x = x->left;
      else
        x = x->right;
    }
    z->p = y;
    if (y == nil)
      root = z;
    else if (z->key < y->key)
      y->left = z;
    else
      y->right = z;

    z->left = nil;
    z->right = nil;
    z->color = Color::RED;
    _rb_insert_fixup(z);
  }

  void _rb_transplant(Node *u, Node *v) {
    if (u->p == nil)
      root = v;
    else if (u == u->p->left)
      u->p->left = v;
    else
      u->p->right = v;
    u->p = v->p;
  }

  void _rb_delete_fixup(Node *x) {
    Node *w = nullptr;
    while (x != root && x->color == Color::BLACK) {
      if (x == x->p->left) {
        w = x->p->right;
        if (w->color == Color::RED) {
          w->color = Color::BLACK;
          x->p->color = Color::RED;
          left_rotate(x->p);
          w = x->p->right;
        }
        if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
          w->color = Color::RED;
          x = x->p;
        } else {
          if (w->right->color == Color::BLACK) {
            w->left->color = Color::BLACK;
            w->color = Color::RED;
            right_rotate(w);
            w = x->p->right;
          }
          w->color = x->p->color;
          x->p->color = Color::BLACK;
          w->right->color = Color::BLACK;
          left_rotate(x->p);
          x = root;
        }
      } else {
        w = x->p->left;
        if (w->color == Color::RED) {
          w->color = Color::BLACK;
          x->p->color = Color::RED;
          right_rotate(x->p);
          w = x->p->left;
        }
        if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
          w->color = Color::RED;
          x = x->p;
        } else {
          if (w->left->color == Color::BLACK) {
            w->right->color = Color::BLACK;
            w->color = Color::RED;
            left_rotate(w);
            w = x->p->left;
          }
          w->color = x->p->color;
          x->p->color = Color::BLACK;
          w->left->color = Color::BLACK;
          right_rotate(x->p);
          x = root;
        }
      }
    }
    x->color = Color::BLACK;
  }

  void rb_delete(Node *z) {
    Node *y = z;
    Node *x = nullptr;
    Color y_original_color = y->color;
    if (z->left == nil) {
      x = z->right;
      _rb_transplant(z, z->right);
    } else if (z->right == nil) {
      x = z->left;
      _rb_transplant(z, z->left);
    } else {
      y = tree_minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->p == z)
        x->p = y;
      else {
        _rb_transplant(y, y->right);
        y->right = z->right;
        y->right->p = y;
      }
      y->left = z->left;
      y->left->p = y;
      y->color = z->color;
    }
    if (y_original_color == Color::BLACK)
      _rb_delete_fixup(x);
  }
};

string node_str(Node *x) {
  if (x == nullptr)
    return "null";
  else
    return to_string(x->key);
}

int main() {}