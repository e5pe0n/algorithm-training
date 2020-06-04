#include <stdio.h>
#include <vector>

using namespace std;

void LU_decomposition(vector<vector<int>> &A) {
  int N = A.size();
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      A[j][i] /= A[i][i];
    }
    for (int j = i + 1; j < N; ++j) {
      for (int k = i + 1; k < N; ++k) {
        A[j][k] -= A[j][i] * A[i][k];
      }
    }
  }
}

int main() {
  vector<vector<int>> A = {{2, 3, 1, 5}, {6, 13, 5, 19}, {2, 19, 10, 23}, {4, 10, 11, 31}};

  LU_decomposition(A);

  int N = A.size();

  printf("[");
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("[");
    for (int j = 0; j < N; ++j) {
      printf("%d, ", A[i][j]);
    }
    printf("]");
    if (i < N - 1) {
      printf("\n");
    }
  }
  printf("]\n");
}
