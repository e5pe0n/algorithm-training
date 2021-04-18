#include "03_02_01.cpp"
#include <vector>
using namespace std;
typedef long long ll;

class SetOfStack {
  vector<Stack> stacks;
  ll each_capacity;

  void append_stack() {
    stacks.push_back(Stack(each_capacity));
  }

public:
  SetOfStack(ll _each_capacity) : each_capacity(_each_capacity) {}

  void push(ll x) {
    for (auto s : stacks) {
      if (!s.is_full()) {
        s.push(x);
        return;
      }
    }
    append_stack();
    stacks[stacks.size() - 1].push(x);
  }

  ll pop() {
    ll i = stacks.size() - 1;
    if (stacks[i].is_empty()) {
      for (; i >= 0; --i) {
        if (stacks[i].is_empty())
          stacks.pop_back();
        else
          break;
      }
    }
    if (i >= 0) return stacks[i].pop();
    throw ese;
  }

  ll pop_at(ll i) {
    if (i == stacks.size() - 1) return pop();
    return stacks[i].pop();
  }
};