#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

using namespace std;

default_random_engine generator;

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

int _partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (A[j] <= x) {
      ++i;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

int randomized_partition(int *A, int p, int r) {
  uniform_int_distribution<int> distribution(p, r);
  int i = distribution(generator);
  swap(A[i], A[r]);
  return _partition(A, p, r);
}

int randomized_select(int *A, int p, int r, int i) {
  if (p == r)
    return A[p];
  int q = randomized_partition(A, p, r);
  // This line is redundant but it is true on semantic: recursion
  // because i should express i-th least between p and r.
  int k = q - p + 1;
  if (i == k) {
    return A[q];
  } else if (i < k) {
    return randomized_select(A, p, q - 1, i);
  } else {
    return randomized_select(A, q + 1, r, i - k);
  }
}

int main() {
  int X[] = {3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
  int Y[] = {3, 2, 9, 0, 7, 5, 4, 8, 6};

  Arr arr_X{X, int(sizeof(X) / sizeof(X[0]))};
  Arr arr_Y{Y, int(sizeof(Y) / sizeof(Y[0]))};

  unordered_map<string, Arr *> cases{{"X", &arr_X}, {"Y", &arr_Y}};
  for (auto &p : cases) {
    cout << "# " << p.first << ": " << p.second->arr_str() << "\n";
    int i = randomized_select(p.second->arr, 0, p.second->size - 1, 9);
    cout << "answer: " << to_string(i) << "\n" << endl;
  }
}