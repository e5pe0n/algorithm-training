// Cracking the Coding Interview p.227
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

struct FixedMultiStack {
  ll num_of_stack = 3;
  ll capacity;
  vector<ll> vals;
  vector<ll> sizes;

  FixedMultiStack(ll size) : capacity(size) {
    vals = vector<ll>(size * num_of_stack);
    sizes = vector<ll>(num_of_stack);
  }

  void push(ll stack_num, ll val) {
    if (is_full(stack_num)) throw fse;
    ++sizes[stack_num];
    vals[index_of_top(stack_num)] = val;
  }

  ll pop(ll stack_num) {
    if (is_empty(stack_num)) throw ese;
    ll top_idx = index_of_top(stack_num);
    ll val = vals[top_idx];
    vals[top_idx] = 0;
    --sizes[stack_num];
    return val;
  }

  ll peek(ll stack_num) {
    if (is_empty(stack_num)) throw ese;
    return vals[index_of_top(stack_num)];
  }

  bool is_empty(ll stack_num) {
    return sizes[stack_num] == 0;
  }

  bool is_full(ll stack_num) {
    return sizes[stack_num] == capacity;
  }

  ll index_of_top(ll stack_num) {
    ll offset = stack_num * capacity;
    ll size = sizes[stack_num];
    return offset + size - 1;
  }
};
