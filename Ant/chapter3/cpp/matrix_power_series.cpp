#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;

int n, k, M;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vi(B[0].size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < B.size(); ++k) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
      }
    }
  }
  return C;
}

mat pow(mat A, int n) {
  mat B(A.size(), vi(A.size()));
  for (int i = 0; i < A.size(); ++i) {
    B[i][i] = 1;
  }
  while (n > 0) {
    if (n & 1) {
      B = mul(B, A);
    }
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

int main() {
  ifstream ifs("../testset/matrix_power_series/test1.txt");
  ifs >> n >> k >> M;
  mat A(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ifs >> A[i][j];
    }
  }
  mat B(n * 2, vi(n * 2));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      B[i][j] = A[i][j];
    }
    B[n + i][i] = B[n + i][n + i] = 1;
  }
  B = pow(B, k + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a = B[n + i][j];
      if (i == j) {
        a = (a + M - 1) % M;
      }
      printf("%d%c", a, j == n - 1 ? '\n' : ' ');
    }
  }
}