#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> hello(vector<int> &vec) {
  // vector<int> res_vec{vec};
  vector<int> res_vec(vec);
  res_vec[0] = 100;
  return res_vec;
}

int main() {
  vector<int> vec_a{1, 2, 3};
  vector<int> res = hello(vec_a);
  for (auto &v : vec_a) {
    cout << v << ", ";
  }
  cout << endl;
  for (auto &v : res) {
    cout << v << ", ";
  }
  cout << endl;

  vector<vector<int>> vec_b(2, vector<int>(3));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      vec_b[i][j] = 10 * i + j;
    }
  }
  for (auto &vec : vec_b) {
    for (auto &v : vec) {
      cout << v << ", ";
    }
  }
  cout << endl;
}