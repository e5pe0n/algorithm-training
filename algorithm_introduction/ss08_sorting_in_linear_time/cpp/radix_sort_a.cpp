#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int work_a[100][8];
int work_b[100][8];
int C[100];

struct Arr {
  int *arr;
  int size;
  int k;
  int d;

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

void counting_sort(int size_a, int k, int idx) {
  for (int i = 0; i <= k; ++i) {
    C[i] = 0;
  }
  for (int i = 0; i < size_a; ++i) {
    C[work_a[i][idx]] += 1;
  }
  for (int i = 0; i < k; ++i) {
    C[i + 1] += C[i];
  }
  for (int i = size_a - 1; i >= 0; --i) {
    int t = work_a[i][idx];
    swap(work_b[C[t] - 1], work_a[i]);
    --C[t];
  }
}

void radix_sort(int *arr, int size, int k, int d) {
  for (int i = 0; i < size; ++i) {
    string s = to_string(arr[i]);
    for (int j = 0; j < d; ++j) {
      work_a[i][j] = s[j] - '0';
      work_b[i][j] = s[j] - '0';
    }
  }
  for (int i = d - 1; i >= 0; --i) {
    counting_sort(size, k, i);
    swap(work_a, work_b);
  }
  for (int i = 0; i < size; ++i) {
    string s = "";
    for (int j = 0; j < d; ++j) {
      s += to_string(work_a[i][j]);
    }
    arr[i] = stoi(s);
  }
}

int main() {
  int k = 9;
  int X[] = {329, 457, 657, 839, 436, 720, 355};
  int Y[] = {3297, 4576, 6575, 8394, 4363, 7202, 3551};

  Arr arr_X{X, int(sizeof(X) / sizeof(X[0])), 9, 3};
  Arr arr_Y{Y, int(sizeof(Y) / sizeof(Y[0])), 9, 4};

  unordered_map<string, Arr *> cases = {{"X", &arr_X}, {"Y", &arr_Y}};
  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "before: " << p.second->arr_str() << "\n";
    radix_sort(p.second->arr, p.second->size, p.second->k, p.second->d);
    cout << "after: " << p.second->arr_str() << "\n" << endl;
  }
}