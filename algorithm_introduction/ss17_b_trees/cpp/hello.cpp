#include <memory>
#include <stdio.h>

using namespace std;

struct Node {
  int key;
  Node(int key) : key(key) {}
};

struct Tree {
  shared_ptr<Node> root;
};

shared_ptr<Node> allocate_node() {
  auto x = make_shared<Node>(1);
  return x;
}

void create_tree(Tree *T) { T->root = allocate_node(); }

int main() {
  Tree T;
  create_tree(&T);
  printf("%d\n", T.root->key);
}