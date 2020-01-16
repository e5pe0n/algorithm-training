#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Arr {
  int *arr;
  int size;
};

int parent(int i) { return (i - 1) >> 1; }

int left(int i) { return ((i + 1) << 1) - 1; }

int right(int i) { return (i + 1) << 1; }

void max_heapify(int A[], int last_heap_idx, int i) {
  int largest = i;
  int l = left(i);
  int r = right(i);
  if (l <= last_heap_idx && A[l] > A[largest]) {
    largest = l;
  }
  if (r <= last_heap_idx && A[r] > A[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(A[i], A[largest]);
    max_heapify(A, last_heap_idx, largest);
  }
}

void build_max_heap(int A[], int arr_size) {
  int heap_size = arr_size;
  for (int i = (heap_size >> 1) - 1; i >= 0; --i) {
    max_heapify(A, heap_size - 1, i);
  }
}

void heapsort(int A[], int arr_size) {
  build_max_heap(A, arr_size);
  for (int i = arr_size - 1; i >= 0; --i) {
    swap(A[0], A[i]);
    max_heapify(A, i - 1, 0);
  }
}

int main() {
  int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int B[] = {4, 1, 3, 2, 16, 9, 10, 14, 8};
  Arr arr_A{A, sizeof(A) / sizeof(A[0])};
  Arr arr_B{B, sizeof(B) / sizeof(B[0])};
  unordered_map<string, Arr> cases{{"A", arr_A}, {"B", arr_B}};

  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "before: [";
    for (int i = 0; i < p.second.size; ++i) {
      cout << p.second.arr[i] << ", ";
    }
    cout << "]\n";

    heapsort(p.second.arr, p.second.size);

    cout << "after: [";
    for (int i = 0; i < p.second.size; ++i) {
      cout << p.second.arr[i] << ", ";
    }
    cout << "]\n\n";
  }
}