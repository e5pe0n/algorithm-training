#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

struct Arr {
  int *arr;
  int size;

  Arr(int *new_arr, int new_size) {
    arr = new_arr;
    size = new_size;
  }
};

int main() {
  int A[] = {10, 11, 12};
  int B[] = {20, 21, 22};
  Arr arr_A(A, sizeof(A) / sizeof(A[0]));
  Arr arr_B(B, sizeof(B) / sizeof(B[0]));
  unordered_map<string, Arr> dict{{"A", arr_A}, {"B", arr_B}};

  for (auto &p : dict) {
    int size = p.second.size;
    cout << p.first << ": [";
    for (int i = 0; i < size; ++i) {
      cout << p.second.arr[i] << ", ";
    }
    cout << "]\n";
  }
}