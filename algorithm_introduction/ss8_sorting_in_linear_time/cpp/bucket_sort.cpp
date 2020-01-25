#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

float B[10][10];
int counter[10]{};

string arr_str(float *arr, int size) {
  string s = "[";
  for (int i = 0; i < size; ++i) {
    s += to_string(arr[i]);
    s += ", ";
  }
  s += "]";
  return s;
}

void insertion_sort(float *A, int size) {
  if (size <= 0)
    return;
  for (int i = 1; i < size; ++i) {
    int j = i - 1;
    float t = A[i];
    while (j >= 0 && A[j] > t) {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = t;
  }
}

void bucket_sort(float *A, int size) {
  for (int i = 0; i < size; ++i) {
    int idx = int(size * A[i]);
    B[idx][counter[idx]] = A[i];
    ++counter[idx];
  }
  for (int i = 0; i < size; ++i) {
    insertion_sort(B[i], counter[i]);
  }
  int idx = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < counter[i]; ++j) {
      A[idx++] = B[i][j];
    }
  }
}

int main() {
  float X[] = {.78, .17, .39, .26, .72, .94, .21, .12, .23, .68};
  int size = 10;

  cout << "# X\n";
  cout << "before: " << arr_str(X, size) << "\n";
  bucket_sort(X, size);
  cout << "after: " << arr_str(X, size) << "\n" << endl;
}
