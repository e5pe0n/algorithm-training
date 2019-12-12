#include <iostream>

using namespace std;

const int INF = 1'000'000'000;

void display_array(const int arr[], size_t size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << ", ";
  }
  cout << endl;
}

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int left[n1 + 1];
  int right[n2 + 1];

  for (int i = 0; i < n1; ++i) {
    left[i] = arr[p + i];
  }
  for (int i = 0; i < n2; ++i) {
    right[i] = arr[q + i + 1];
  }

  left[n1] = INF;
  right[n2] = INF;

  int i = 0;
  int j = 0;
  for (int k = p; k <= r; ++k) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      ++i;
    } else {
      arr[k] = right[j];
      ++j;
    }
  }
}

void merge_sort(int arr[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;

    merge_sort(arr, p, q);
    merge_sort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
}

int main() {
  int A[] = {13, 15, 11, 14, 12};
  int B[] = {13, 15, 11, 14, 12, 16};

  cout << "A" << endl;
  cout << "before: ";
  display_array(A, end(A) - begin(A));

  merge_sort(A, 0, end(A) - begin(A) - 1);

  cout << "after: ";
  display_array(A, end(A) - begin(A));
  cout << endl;

  cout << "B" << endl;
  cout << "before: ";
  display_array(B, end(B) - begin(B));

  merge_sort(B, 0, end(B) - begin(B) - 1);

  cout << "after: ";
  display_array(B, end(B) - begin(B));
}