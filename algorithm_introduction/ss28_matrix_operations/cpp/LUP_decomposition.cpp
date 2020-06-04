#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> LUP_decomposition(vector<vector<float>> &A) {
  int N = A.size();
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    P[i] = i;
  }
  for (int k = 0; k < N - 1; ++k) {
    int p = 0;
    int _k = 0;
    for (int i = k; i < N; ++i) {
      if (abs(A[i][k]) > p) {
        p = abs(A[i][k]);
        _k = i;
      }
    }
    if (p == 0) {
      throw "Error: Singular matrix";
    }
    swap(P[k], P[_k]);
    swap(A[k], A[_k]);
    for (int i = k + 1; i < N; ++i) {
      A[i][k] /= A[k][k];
      for (int j = k + 1; j < N; ++j) {
        A[i][j] -= A[i][k] * A[k][j];
      }
    }
  }
  return P;
}

int main() {
  vector<vector<float>> A{{2, 0, 2, 0.6}, {3, 3, 4, -2}, {5, 5, 4, 2}, {-1, -2, 3.4, -1}};

  vector<int> P = LUP_decomposition(A);

  int N = A.size();

  printf("A:\n");
  printf("[");
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("[");
    for (int j = 0; j < N; ++j) {
      printf("%f, ", A[i][j]);
    }
    printf("]");
    if (i < N - 1) {
      printf("\n");
    }
  }
  printf("]\n");

  printf("P: [");
  for (int i = 0; i < N; ++i) {
    printf("%d, ", P[i]);
  }
  printf("]\n");
}