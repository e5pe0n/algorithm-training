// Cracking the Coding Interview p.234
#include <vector>
using namespace std;
typedef long long ll;

class EmptyStackException : public exception {
  virtual const char *what() const throw() {
    return "stack is empty";
  }
} ese;

class FullStackException : public exception {
  virtual const char *what() const throw() {
    return "stack is full";
  }
} fse;

class Node {
public:
  Node *above, *below;
  ll value;
  Node(ll _value) : value(_value) {}
};

class Stack {
private:
  ll capacity;

public:
  Node *top, *btm;
  ll size = 0;

  Stack(ll _capacity) : capacity(_capacity) {}

  bool is_full() {
    return size == capacity;
  }

  bool is_empty() {
    return size == 0;
  }

  void join(Node *above, Node *below) {
    if (below != nullptr) below->above = above;
    if (above != nullptr) above->below = below;
  }

  bool push(ll x) {
    if (size >= capacity) return false;
    ++size;
    Node *n = new Node(x);
    if (size == 1) btm = n;
    join(n, top);
    top = n;
    return true;
  }

  ll pop() {
    Node *t = top;
    ll x = t->value;
    top = top->below;
    delete t;
    --size;
    return x;
  }

  ll rm_btm() {
    Node *b = btm;
    ll x = b->value;
    btm = btm->above;
    delete b;
    if (btm != nullptr) btm->below = nullptr;
    --size;
    return x;
  }
};

class SetOfStack {
  vector<Stack> stacks;
  ll capacity;

public:
  SetOfStack(ll _capacity) : capacity(_capacity) {}

  Stack *get_last_stack() {
    if (stacks.size() == 0) return nullptr;
    return &stacks[stacks.size() - 1];
  }

  void push(ll x) {
    Stack *last = get_last_stack();
    if (last != nullptr && !last->is_full())
      last->push(x);
    else {
      stacks.emplace_back(Stack(capacity));
      stacks[stacks.size() - 1].push(x);
    }
  }

  ll pop() {
    Stack *last = get_last_stack();
    if (last == nullptr) throw ese;
    ll x = last->pop();
    if (last->is_empty()) stacks.pop_back();
    return x;
  }

  bool is_empty() {
    Stack *last = get_last_stack();
    return last == nullptr || last->is_empty();
  }

  ll pop_at(ll idx) {
    return left_shift(idx, true);
  }

  ll left_shift(ll idx, bool rm_top) {
    Stack *stack = &stacks[idx];
    ll rmd_item;
    if (rm_top)
      rmd_item = stack->pop();
    else
      rmd_item = stack->rm_btm();
    if (stack->is_empty()) {
      stacks.pop_back();
    } else if (stacks.size() > idx + 1) {
      ll x = left_shift(idx + 1, false);
      stack->push(x);
    }
    return rmd_item;
  }
};