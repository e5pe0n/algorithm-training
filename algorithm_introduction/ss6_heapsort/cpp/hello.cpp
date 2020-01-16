#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

struct Arr {
  int *arr;
  int size;
  int counter = 0;

  Arr(int *new_arr, int new_size) {
    arr = new_arr;
    size = new_size;
  }

  void count(int c) { counter += c; }
};

int main() {
  int A[] = {10, 11, 12};
  Arr arr_A(A, sizeof(A) / sizeof(A[0]));
  unordered_map<string, Arr *> cases = {{"A", &arr_A}};
  for (auto &p : cases) {
    cout << p.first << ": [";
    for (int i = 0; i < p.second->size; ++i) {
      cout << p.second->arr[i] << ", ";
    }
    cout << "], counter=" << to_string(p.second->counter) << "\n";
  }
  arr_A.arr[0] = 100;
  arr_A.counter = 1000;
  for (auto &p : cases) {
    cout << p.first << ": [";
    for (int i = 0; i < p.second->size; ++i) {
      cout << p.second->arr[i] << ", ";
    }
    cout << "], counter=" << to_string(p.second->counter) << "\n";
  }
}