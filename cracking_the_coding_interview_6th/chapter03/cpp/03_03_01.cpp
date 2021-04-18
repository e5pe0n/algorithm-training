#include "03_02_01.cpp"
#include <vector>
using namespace std;
typedef long long ll;

class SetOfStack {
  vector<Stack> stacks;
  ll each_capacity;
  ll stack_idx = 0;

public:
  SetOfStack(ll _each_capacity) : each_capacity(_each_capacity) {
    stacks.push_back(Stack(each_capacity));
  }

  void push(ll x) {
    if (stacks[stack_idx].is_full()) {
      stacks.push_back(Stack(each_capacity));
      ++stack_idx;
    }
    stacks[stack_idx].push(x);
  }

  ll pop() {
    if (stacks[stack_idx].is_empty()) {
      if (stack_idx == 0) throw ese;
      stacks.pop_back();
      --stack_idx;
    }
    return stacks[stack_idx].pop();
  }
};
