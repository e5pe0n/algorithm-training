#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_n 100
#define M 10007

using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;

int n, k;

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
  ifstream ifs("../testset/num_of_len_k_paths_of_graph/test1.txt");
  ifs >> n >> k;
  mat G(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ifs >> G[i][j];
    }
  }
  G = pow(G, k);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res = (res + G[i][j]) % M;
    }
  }
  printf("%d\n", res);
}