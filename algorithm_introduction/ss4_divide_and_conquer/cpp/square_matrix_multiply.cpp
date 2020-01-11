#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> square_matrix_multiply(int A[][2], int B[][2]) {
  int n = sizeof(A[0]) / sizeof(A[0][0]);
  vector<vector<int>> res(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return res;
}

int main() {
  int A[2][2] = {{0, 1}, {2, 3}};
  int B[2][2] = {{4, 5}, {6, 7}};
  vector<vector<int>> res(2, vector<int>(2, 0));

  res = square_matrix_multiply(A, B);
  cout << "[\n";
  for (int i = 0; i < 2; ++i) {
    cout << "  [";
    for (int j = 0; j < 2; ++j) {
      cout << res[i][j] << ", ";
    }
    cout << "]\n";
  }
  cout << "]" << endl;
}