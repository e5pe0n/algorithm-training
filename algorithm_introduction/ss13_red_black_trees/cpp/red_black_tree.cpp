#include <stdio.h>
#include <string>

using namespace std;

struct Node {
  int key;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *p = nullptr;
  int color = 0; // black: 0, red: 1
  Node(int key, Node *p, int color) : key(key), p(p), color(color) {}
};

struct Tree {
  Node *root;
  Node *nil = nullptr;
  Tree(Node *root) : root(root) {}
};

string node_str(Node *x) {
  if (x == nullptr)
    return "null";
  else
    return to_string(x->key);
}

void left_rotate(Tree *T, Node *x) {
  Node *y = x->right;

  x->right = y->left;
  if (y->left != T->nil)
    y->left->p = x;
  y->p = x->p;

  if (x->p == T->nil)
    T->root = y;
  else if (x == x->p->left)
    x->p->left = y;
  else
    x->p->right = y;

  y->left = x;
  x->p = y;
}

void right_rotate(Tree *T, Node *x) {
  Node *y = x->left;

  x->left = y->right;
  if (y->right != T->nil)
    y->right->p = x;
  y->p = x->p;

  if (x->p == T->nil)
    T->root = y;
  else if (x->p->left)
    x->p->left = y;
  else
    x->p->right = y;

  y->right = x;
  x->p = y;
}

int main() {}