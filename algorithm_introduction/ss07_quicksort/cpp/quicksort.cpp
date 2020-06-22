#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int _partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1; // i is the last idx of smaller array
  for (int j = p; j < r; ++j) {
    if (A[j] <= x) {
      i += 1;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1; // exchange the value of the first idx of larger array with a pivot
}

void quicksort(int *A, int p, int r) {
  if (p < r) {
    int q = _partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
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
  Arr arr_B{B, sizeof(B) / sizeof(B[0])};

  unordered_map<string, Arr *> cases = {{"A", &arr_A}, {"B", &arr_B}};
  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "before:" << p.second->arr_str() << "\n";
    quicksort(p.second->arr, 0, p.second->size - 1);
    cout << "after:" << p.second->arr_str() << "\n" << endl;
  }
}
