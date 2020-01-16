#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

struct MaxPriorityQueue {
  int *arr;
  int capacity;
  int last_heap_idx;

  string display() {
    string s = "[";
    for (int i = 0; i <= last_heap_idx; ++i) {
      s += to_string(arr[i]);
      s += ", ";
    }
    s += "]";
    return s;
  }

  MaxPriorityQueue(int *ini_arr, const int &ini_capacity, int ini_last_heap_idx)
      : arr(ini_arr), capacity(ini_capacity), last_heap_idx(ini_last_heap_idx) {
    _build_max_heap();
  }

  int _parent(int i) { return (i - 1) >> 1; }

  int _left(int i) { return ((i + 1) << 1) - 1; }

  int _right(int i) { return (i + 1) << 1; }

  void _max_heapify(int i) {
    int largest = i;
    int l = _left(i);
    int r = _right(i);
    if (l <= last_heap_idx && arr[l] > arr[largest]) {
      largest = l;
    }
    if (r <= last_heap_idx && arr[r] > arr[largest]) {
      largest = r;
    }
    if (largest != i) {
      swap(arr[i], arr[largest]);
      _max_heapify(largest);
    }
  }

  void _build_max_heap() {
    for (int i = _parent(last_heap_idx); i >= 0; --i) {
      _max_heapify(i);
    }
  }

  int heap_maximum() { return arr[0]; }

  int heap_extract_max() {
    if (last_heap_idx < 0) {
      throw "Heap underflow";
    }
    int max_val = arr[0];
    arr[0] = arr[last_heap_idx];
    last_heap_idx -= 1;
    _max_heapify(0);
    return max_val;
  }

  void _heap_increase_key(int i, int key) {
    if (key < arr[i]) {
      throw "New key (=" + to_string(key) +
          ") must be greater than current key (=" + to_string(arr[i]) + ".)";
    }
    arr[i] = key;
    while (i > 0 && arr[_parent(i)] < arr[i]) {
      swap(arr[_parent(i)], arr[i]);
      i = _parent(i);
    }
  }

  void max_heap_insert(int key) {
    last_heap_idx += 1;
    arr[last_heap_idx] = numeric_limits<int>::lowest();
    _heap_increase_key(last_heap_idx, key);
  }
};

int main() {
  int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int B[] = {4, 1, 3, 2, 16, 9, 10, 14, 8};
  MaxPriorityQueue que_A(A, 100, (int)(sizeof(A) / sizeof(A[0]) - 1));
  MaxPriorityQueue que_B(B, 100, (int)(sizeof(B) / sizeof(B[0]) - 1));
  unordered_map<string, MaxPriorityQueue *> cases{{"A", &que_A}, {"B", &que_B}};

  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << p.second->display() << "\n";
    cout << to_string(p.second->heap_extract_max()) << "\n";
    cout << p.second->display() << "\n";
    cout << to_string(p.second->heap_extract_max()) << "\n";
    cout << p.second->display() << "\n";
    cout << to_string(p.second->heap_extract_max()) << "\n";
    cout << p.second->display() << "\n";
    cout << to_string(p.second->heap_extract_max()) << "\n";
    cout << p.second->display() << "\n";
    p.second->max_heap_insert(100);
    cout << p.second->display() << "\n";
    p.second->max_heap_insert(6);
    cout << p.second->display() << "\n";
    cout << to_string(p.second->heap_extract_max()) << "\n";
    cout << p.second->display() << "\n";
    cout << to_string(p.second->heap_extract_max()) << "\n";
    cout << p.second->display() << "\n";
    cout << endl;
  }
}