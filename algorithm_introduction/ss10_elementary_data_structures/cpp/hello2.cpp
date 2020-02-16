#include <deque>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Using deque
  deque<int> dq{1, 2, 3};

  dq.push_back(4);
  cout << "dq.back(): " << to_string(dq.back()) << "\n";
  dq.pop_back(); // return none!
  cout << "dq.back(): " << to_string(dq.back()) << "\n";

  dq.push_front(5);
  cout << "dq.top(): " << to_string(dq.front()) << "\n";
  dq.pop_front();
  cout << "dq.top(): " << to_string(dq.front()) << "\n" << endl;

  // Using stack (sounds redundant)
  // stack use a container(deque(default), vector, list)
  deque<int> dq1{1, 2, 3};
  stack<int> stk1(dq1);

  stk1.push(4);
  cout << "stk1.top(): " << to_string(stk1.top()) << "\n";
  stk1.pop();
  cout << "stk1.top(): " << to_string(stk1.top()) << "\n" << endl;

  deque<int> dq2(3, -1); // deque(size, initial_value)
  stack<int> stk2(dq2);

  cout << "stk2.size(): " << to_string(stk2.size()) << "\n";
  cout << "stk2.top(): " << to_string(stk2.top()) << "\n";
  stk2.pop();
  cout << "stk2.top(): " << to_string(stk2.top()) << "\n" << endl;
}