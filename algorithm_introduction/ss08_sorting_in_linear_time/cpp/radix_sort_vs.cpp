#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int C[100];

struct Arr {
  vector<int> &vec;
  int k;
  int d;

  string arr_str() {
    string s = "[";
    for (auto &i : vec) {
      s += to_string(i);
      s += ", ";
    }
    s += "]";
    return s;
  }
};

int c2i(char c) { return c - '0'; }

vector<string> counting_sort(vector<string> &vec, int k, int idx) {
  vector<string> res_vec(vec);
  int size = vec.size();
  for (int i = 0; i <= k; ++i) {
    C[i] = 0;
  }
  for (int i = 0; i < size; ++i) {
    C[c2i(vec[i][idx])] += 1;
  }
  for (int i = 0; i < k; ++i) {
    C[i + 1] += C[i];
  }
  for (int i = size - 1; i >= 0; --i) {
    res_vec[C[c2i(vec[i][idx])] - 1] = vec[i];
    --C[c2i(vec[i][idx])];
  }
  return res_vec;
}

void radix_sort(vector<int> &vec, int k, int d) {
  vector<string> work_a(vec.size());
  vector<string> work_b(vec.size());
  for (int i = 0; i < vec.size(); ++i) {
    work_a[i] = to_string(vec[i]);
  }
  for (int i = d - 1; i >= 0; --i) {
    work_b = counting_sort(work_a, k, i);
    swap(work_a, work_b);
  }
  for (int i = 0; i < vec.size(); ++i) {
    vec[i] = stoi(work_a[i]);
  }
}

int main() {
  vector<int> X{329, 457, 657, 839, 436, 720, 355};
  vector<int> Y{3297, 4576, 6575, 8394, 4363, 7202, 3551};

  Arr arr_X{X, 9, 3};
  Arr arr_Y{Y, 9, 3};

  unordered_map<string, Arr *> cases = {{"X", &arr_X}, {"Y", &arr_Y}};
  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "before: " << p.second->arr_str() << "\n";
    radix_sort(p.second->vec, p.second->k, p.second->d);
    cout << "after: " << p.second->arr_str() << "\n" << endl;
  }
}