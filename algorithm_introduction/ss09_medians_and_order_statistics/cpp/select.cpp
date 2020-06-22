#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

string _arr_str(int *A, int size) {
  stringstream ss;
  ss << "[";
  for (int i = 0; i < size; ++i) {
    if (i > 0) {
      ss << " ";
    }
    ss << setw(2) << to_string(A[i]) << ", ";
    if (i % 5 == 4 && i != size - 1)
      ss << "\n";
  }
  ss << "]";
  return ss.str();
}

string _arr_str_with_range(int *A, int p, int r) {
  int size = r - p + 1;
  stringstream ss;
  ss << "[";
  for (int i = 0; i < size; ++i) {
    if (i > 0) {
      ss << " ";
    }
    ss << setw(2) << to_string(A[p + i]) << ", ";
    if (i % 5 == 4 && i != size - 1)
      ss << "\n";
  }
  ss << "]";
  return ss.str();
}

void _insertion_sort(int *A, int p, int r) {
  for (int i = p + 1; i <= r; ++i) {
    int j = i - 1;
    int k = A[i];
    while (j >= 0 && A[j] > A[i]) {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = k;
  }
}

int _partition(int *A, int p, int r, int x) {
  int i = p - 1;
  for (int j = p; j <= r; ++j) {
    if (A[j] < x) {
      swap(A[++i], A[j]);
    }
  }
  return i + 1;
}

int _get_median(int *A, int p, int r) {
  int m = (r - p) / 2;
  return A[p + m];
}

int _select(int *A, int p, int r, int z) {
  // Find z-th least value.
  // Be aware that z starts from 0.

  if (p == r)
    return A[p];

  int medians[100]{};
  int j = 0;
  int q = (r - p + 1) / 5;
  int s = (r - p + 1) % 5;

  // mod 5 == 0
  for (int i = 0; i < q; ++i) {
    int l = p + 5 * i;
    _insertion_sort(A, l, l + 4);
    medians[j++] = _get_median(A, l, l + 4);
  }

  // mod 5 > 0
  if (s > 0) {
    _insertion_sort(A, r - s + 1, r);
    medians[j++] = _get_median(A, r - s + 1, r);
  }

  int x = _select(medians, 0, j - 1, (j - 1) / 2);
  int k = _partition(A, p, r, x) - p;
  if (k == z) {
    return x;
  } else if (z < k) {
    return _select(A, p, p + k - 1, z);
  } else {
    return _select(A, p + k + 1, r, z - k - 1);
  }
}

int main() {
  int X[] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 17, 18,
             19, 13, 14, 15, 16, 20, 21, 25, 26, 27, 28, 22, 23, 24};

  int x_size = int(sizeof(X) / sizeof(X[0]));

  cout << "X: \n";
  cout << _arr_str(X, x_size) << endl;
  cout << "0-th least value: " << _select(X, 0, x_size - 1, 0) << endl;
  cout << "6-th least value: " << _select(X, 0, x_size - 1, 6) << endl;
  cout << "10-th least value: " << _select(X, 0, x_size - 1, 10) << endl;
  cout << "27-th least value: " << _select(X, 0, x_size - 1, 27) << endl;
}