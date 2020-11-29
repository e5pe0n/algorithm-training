#include <fstream>
#include <stdio.h>
#include <vector>

#define MOD 1000

using namespace std;
typedef vector<int> vi;
typedef vector<vi> mat;

int n;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vi(B[0].size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < B.size(); ++k) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}

mat pow(mat A, int n) {
  mat res(A.size(), vi(A.size()));
  for (int i = 0; i < A.size(); ++i) {
    res[i][i] = 1;
  }
  while (n > 0) {
    if (n & 1) {
      res = mul(res, A);
    }
    A = mul(A, A);
    n >>= 1;
  }
  return res;
}

void solve() {
  mat A(2, vi(2));
  A[0][0] = 3;
  A[0][1] = 5;
  A[1][0] = 1;
  A[1][1] = 3;
  A = pow(A, n);
  printf("%03d\n", (A[0][0] * 2 - 1 + MOD) % MOD);
}

int main() {
  ifstream ifs("../testset/numbers/test2.txt");
  ifs >> n;
  solve();
}