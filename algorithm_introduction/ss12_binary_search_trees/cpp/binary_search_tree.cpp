#include <stdio.h>
#include <string>

using namespace std;

struct Node {
  int key;
  Node *p = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(int key, Node *p) : key(key), p(p) {}
};

struct Tree {
  Node *root = nullptr;
};

void inorder_tree_walk(Node *x) {
  if (x != nullptr) {
    inorder_tree_walk(x->left);
    printf("%d, ", x->key);
    inorder_tree_walk(x->right);
  }
}

// Node *tree_search(Node *x, int k) {
//   if (x == nullptr || k == x->key)
//     return x;
//   if (k < x->key)
//     return tree_search(x->left, k);
//   else
//     return tree_search(x->right, k);
// }

Node *tree_search(Node *x, int k) {
  while (x != nullptr && k != x->key) {
    if (k < x->key)
      x = x->left;
    else
      x = x->right;
  }
  return x;
}

Node *tree_maximum(Node *x) {
  while (x->left != nullptr)
    x = x->left;
  return x;
}

Node *tree_minimum(Node *x) {
  while (x->right != nullptr)
    x = x->right;
  return x;
}

Node *tree_successor(Node *x) {
  if (x->right != nullptr) {
    return tree_minimum(x->right);
  }
  Node *y = x->p;
  while (y != nullptr && x == y->right) {
    x = y;
    y = x->p;
  }
  return y;
}

void tree_insert(Tree *T, Node *z) {
  Node *y = nullptr;
  Node *x = T->root;
  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->p = y;
  if (y == nullptr)
    T->root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

void transplant(Tree *T, Node *u, Node *v) {
  if (u->p == nullptr)
    T->root = v;
  else if (u->p->right == u)
    u->p->right = v;
  else
    u->p->left = v;
  if (v != nullptr)
    v->p = u->p;
}

void tree_delete(Tree *T, Node *z) {
  if (z->left == nullptr)
    transplant(T, z, z->right);
  else if (z->right == nullptr)
    transplant(T, z, z->left);
  else {
    Node *y = tree_minimum(z->right);
    if (y->p != z) {
      transplant(T, y, y->right);
      y->right = z->right;
      y->right->p = y;
    }
    transplant(T, z, y);
    y->left = z->left;
    y->left->p = y;
  }
}

string node_str(Node *x) {
  if (x == nullptr)
    return "null";
  else
    return to_string(x->key);
}

int main() {
  Node n12(12, nullptr);
  Node n5(5, &n12);
  Node n2(2, &n5);
  Node n9(9, &n5);
  Node n10(10, &n9);
  Node n18(18, &n12);
  Node n15(15, &n18);
  Node n17(17, &n15);
  Node n19(19, &n18);

  n12.left = &n5;
  n12.right = &n18;
  n5.left = &n2;
  n5.right = &n9;
  n9.right = &n10;
  n18.left = &n15;
  n18.right = &n19;
  n15.right = &n17;

  Tree T{&n12};

  printf("inorder_tree_walk: ");
  inorder_tree_walk(T.root);
  printf("\n");

  Node *res = tree_search(&n12, 5);
  printf("tree_search(&n12, 5): %s\n", node_str(res).c_str());

  res = tree_search(&n12, 3);
  printf("tree_search(&n12, 3): %s\n", node_str(res).c_str());

  res = tree_successor(&n10);
  printf("tree_successor(&n10): %s\n", node_str(res).c_str());

  res = tree_successor(&n19);
  printf("tree_successor(&n19): %s\n", node_str(res).c_str());

  Node n13(13, nullptr);
  printf("tree_insert(&T, &n13)");
  tree_insert(&T, &n13);

  printf("inorder_tree_walk: ");
  inorder_tree_walk(T.root);
  printf("\n");

  printf("tree_delete(&T, &n15)");
  tree_delete(&T, &n15);

  printf("inorder_tree_walk: ");
  inorder_tree_walk(T.root);
  printf("\n");
}