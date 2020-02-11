#include <iostream>
#include <string>

using namespace std;

struct _Stack {
  int _capacity;
  int *_arr;
  int _top = -1;

  _Stack(int capacity) : _capacity(capacity) { _arr = new int[capacity]{}; }

  bool _stack_empty() { return _top < 0; }
  void _push(int x) { _arr[++_top] = x; }
  int _pop() {
    if (_stack_empty())
      throw "Underflow";
    else
      return _arr[_top--];
  }
  string _arr_str() {
    string s = "[";
    for (int i = 0; i <= _top; ++i) {
      s += to_string(_arr[i]);
      s += ", ";
    }
    s += "]\n";
    return s;
  }

  ~_Stack() { delete[] _arr; }
};

int main() {
  _Stack S(10);

  cout << "S._stack_empty(): " << to_string(S._stack_empty()) << "\n";
  S._push(1);
  S._push(2);
  cout << "S: " << S._arr_str() << "\n";
  cout << "S._stack_empty(): " << to_string(S._stack_empty()) << "\n";
  cout << "S.pop(): " << to_string(S._pop()) << "\n";
  cout << "S: " << S._arr_str() << "\n";
}