// Cracking the Coding Interview p.229
#include <exception>
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

struct MultiStack {
  struct StackInfo {
    MultiStack *holder;
    ll start, size, capacity;
    StackInfo(MultiStack *holder, ll _start, ll _capacity)
        : holder(holder), start(_start), capacity(_capacity) {}
    bool is_within_stack_capacity(ll idx) {
      if (idx < 0 || idx >= holder->vals.size()) return false;
      ll contiguous_idx = idx < start ? idx + holder->vals.size() : idx;
      ll end = start + capacity;
      return start <= contiguous_idx && contiguous_idx < end;
    }
    ll last_capacity_idx() {
      return holder->adjust_idx(start + capacity - 1);
    }
    ll last_elem_idx() {
      return holder->adjust_idx(start + size - 1);
    }
    bool is_full() {
      return size == capacity;
    }
    bool is_empty() {
      return size == 0;
    }
  };

  vector<StackInfo> info;
  vector<ll> vals;

  MultiStack(ll num_of_stacks, ll default_size) {
    info = vector<StackInfo>(num_of_stacks);
    for (ll i = 0; i < num_of_stacks; ++i) {
      info[i] = StackInfo(this, default_size * i, default_size);
    }
    vals = vector<ll>(num_of_stacks * default_size);
  }

  void push(ll stack_num, ll val) {
    if (all_stacks_are_full()) throw fse;

    StackInfo *stack = &info[stack_num];
    if (stack->is_full()) expand(stack_num);

    ++stack->size;
    vals[stack->last_elem_idx()] = val;
  }

  ll pop(ll stack_num) {
    StackInfo *stack = &info[stack_num];
    if (stack->is_empty()) throw ese;

    ll val = vals[stack->last_elem_idx()];
    vals[stack->last_elem_idx()] = 0;
    --stack->size;
    return val;
  }

  ll peek(ll stack_num) {
    StackInfo *stack = &info[stack_num];
    return vals[stack->last_elem_idx()];
  }

  void shift(ll stack_num) {
    StackInfo *stack = &info[stack_num];

    if (stack->size >= stack->capacity) {
      ll next_stack = (stack_num + 1) % info.size();
      shift(next_stack);
      ++stack->capacity;
    }

    ll idx = stack->last_capacity_idx();
    while (stack->is_within_stack_capacity(idx)) {
      vals[idx] = vals[previous_idx(idx)];
      idx = previous_idx(idx);
    }

    vals[stack->start] = 0;
    stack->start = next_idx(stack->start);
    --stack->capacity;
  }

  void expand(ll stack_num) {
    shift((stack_num + 1) % info.size());
    ++info[stack_num].capacity;
  }

  ll num_of_elems() {
    ll size = 0;
    for (auto sd : info) {
      size += sd.size;
    }
    return size;
  }

  bool all_stacks_are_full() {
    return num_of_elems() == vals.size();
  }

  ll adjust_idx(ll idx) {
    ll ma = vals.size();
    return ((idx % ma) + ma) % ma;
  }

  ll next_idx(ll idx) {
    return adjust_idx(idx + 1);
  }

  ll previous_idx(ll idx) {
    return adjust_idx(idx - 1);
  }
};