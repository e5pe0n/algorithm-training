#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int i1 = 16;
  int i2 = 10;
  int i1_quo = i1;
  int i2_quo = i2;

  deque<int> dq;
  while (i1_quo > 0) {
    dq.push_back(i1_quo % 2);
    i1_quo /= 2;
  }
  cout << "[";
  while (!dq.empty()) {
    cout << to_string(dq.back()) << ", ";
    dq.pop_back();
  }
  cout << "]\n";

  while (i2_quo > 0) {
    dq.push_back(i2_quo % 2);
    i2_quo /= 2;
  }
  cout << "[";
  while (!dq.empty()) {
    cout << to_string(dq.back()) << ", ";
    dq.pop_back();
  }
  cout << "]\n";
}