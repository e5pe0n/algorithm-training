#include <iostream>

using namespace std;

void display_array(const int arr[], size_t size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << ", ";
  }
  cout << endl;
}

void insertion_sort(int arr[], size_t size) {
  if (size <= 1) return;
  for (int i = 1; i < size; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int A[] = {3, 1, 5, 9, 4};

  cout << "before: ";
  display_array(A, end(A) - begin(A));

  insertion_sort(A, end(A) - begin(A));

  cout << "after: ";
  display_array(A, end(A) - begin(A));
}