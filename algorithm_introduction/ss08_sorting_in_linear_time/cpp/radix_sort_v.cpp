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

vector<vector<int>> counting_sort(vector<vector<int>> &vec, int k, int idx) {
  vector<vector<int>> res_vec(vec);
  int size = vec.size();
  for (int i = 0; i <= k; ++i) {
    C[i] = 0;
  }
  for (int i = 0; i < size; ++i) {
    C[vec[i][idx]] += 1;
  }
  for (int i = 0; i < k; ++i) {
    C[i + 1] += C[i];
  }
  for (int i = size - 1; i >= 0; --i) {
    res_vec[C[vec[i][idx]] - 1] = vec[i];
    --C[vec[i][idx]];
  }
  return res_vec;
}

void radix_sort(vector<int> &vec, int k, int d) {
  vector<vector<int>> work_a(vec.size(), vector<int>(d));
  vector<vector<int>> work_b(vec.size(), vector<int>(d));
  for (int i = 0; i < vec.size(); ++i) {
    string s = to_string(vec[i]);
    for (int j = 0; j < d; ++j) {
      work_a[i][j] = s[j] - '0';
    }
  }
  for (int i = d - 1; i >= 0; --i) {
    work_b = counting_sort(work_a, k, i);
    swap(work_a, work_b);
  }
  for (int i = 0; i < vec.size(); ++i) {
    string s = "";
    for (int j = 0; j < d; ++j) {
      s += to_string(work_a[i][j]);
    }
    vec[i] = stoi(s);
  }
}

int main() {
  vector<int> X{329, 457, 657, 839, 436, 720, 355};
  vector<int> Y{3297, 4576, 6575, 8394, 4363, 7202, 3551};

  Arr arr_X{X, 9, 3};
  Arr arr_Y{Y, 9, 4};

  unordered_map<string, Arr *> cases = {{"X", &arr_X}, {"Y", &arr_Y}};
  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "before: " << p.second->arr_str() << "\n";
    radix_sort(p.second->vec, p.second->k, p.second->d);
    cout << "after: " << p.second->arr_str() << "\n" << endl;
  }
}