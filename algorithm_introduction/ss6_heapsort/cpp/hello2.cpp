#include <iostream>

using namespace std;

struct MaxPriorityQueue {
  int capacity;
  int *arr;

  MaxPriorityQueue(int ini_capacity, int *ini_arr) : capacity(ini_capacity), arr(ini_arr) {}
};

int main() {
  int arr[] = {1, 2, 3};
  MaxPriorityQueue que(3, arr);
  cout << que.capacity << endl;
  for (int i = 0; i < que.capacity; ++i) {
    cout << que.arr[i] << ", ";
  }
  cout << endl;
}
