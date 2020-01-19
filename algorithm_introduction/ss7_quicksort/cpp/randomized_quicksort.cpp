#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

using namespace std;

default_random_engine generator;

int _partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (A[j] <= x) {
      i += 1;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

int _randomized_partition(int *A, int p, int r) {
  uniform_int_distribution<int> distribution(p, r);
  int i = distribution(generator);
  swap(A[i], A[r]);
  return _partition(A, p, r);
}

void _randomized_quicksort(int *A, int p, int r) {
  if (p < r) {
    int q = _randomized_partition(A, p, r);
    _randomized_quicksort(A, p, q - 1);
    _randomized_quicksort(A, q + 1, r);
  }
}

struct Arr {
  int *arr;
  int size;

  string arr_str() {
    string s = "[";
    for (int i = 0; i < size; ++i) {
      s += to_string(arr[i]);
      s += ", ";
    }
    s += "]";
    return s;
  }
};

int main() {
  int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
  int B[] = {2, 8, 7, 1, 3, 5, 6, 4, 9};

  Arr arr_A{A, sizeof(A) / sizeof(A[0])};
  Arr arr_B{B, sizeof(A) / sizeof(B[0])};

  unordered_map<string, Arr *> cases = {{"A", &arr_A}, {"B", &arr_B}};
  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "before: " << p.second->arr_str() << "\n";
    _randomized_quicksort(p.second->arr, 0, p.second->size - 1);
    cout << "after: " << p.second->arr_str() << "\n" << endl;
  }
}
