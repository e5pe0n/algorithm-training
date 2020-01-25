#include <iostream>
#include <string>

using namespace std;

string arr_str(int (*A)[3], int size_A_outer, int size_A_inner) {
  string s = "[";
  for (int i = 0; i < size_A_outer; ++i) {
    s += "[";
    for (int j = 0; j < size_A_inner; ++j) {
      s += to_string(A[i][j]);
      s += ", ";
    }
    s += "], ";
  }
  s += "]";
  return s;
}

int main() {
  int a[][3] = {{1, 2, 3}, {4, 5, 6}};
  cout << arr_str(a, 2, 3) << endl;
  // cout << arr_str(a, int(sizeof(a) / sizeof(a[0])), int(sizeof(a[0]) / sizeof(a[0][0]))) << endl;
}