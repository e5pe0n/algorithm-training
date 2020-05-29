#include <stdio.h>
#include <vector>

using namespace std;

void square_matrix_multiply_recursive(vector<vector<int>> &C, int ic, int jc, vector<vector<int>> &A, int ia,
                                      int ja, vector<vector<int>> &B, int ib, int jb, int N) {
  if (N == 1) {
    C[ic][jc] = A[ia][ja] * B[ib][jb];
  } else {
    vector<vector<int>> T(N, vector<int>(N, 0));

    int ia00 = ia;
    int ja00 = ja;
    int ib00 = ib;
    int jb00 = jb;
    int ic00 = ic;
    int jc00 = jc;
    int it00 = 0;
    int jt00 = 0;

    int ia01 = ia;
    int ja01 = ja + N / 2;
    int ib01 = ib;
    int jb01 = jb + N / 2;
    int ic01 = ic;
    int jc01 = jc + N / 2;
    int it01 = 0;
    int jt01 = N / 2;

    int ia10 = ia + N / 2;
    int ja10 = ja;
    int ib10 = ib + N / 2;
    int jb10 = jb;
    int ic10 = ic + N / 2;
    int jc10 = jc;
    int it10 = N / 2;
    int jt10 = 0;

    int ia11 = ia + N / 2;
    int ja11 = ja + N / 2;
    int ib11 = ib + N / 2;
    int jb11 = jb + N / 2;
    int ic11 = ic + N / 2;
    int jc11 = jc + N / 2;
    int it11 = N / 2;
    int jt11 = N / 2;

    square_matrix_multiply_recursive(C, ic00, jc00, A, ia00, ja00, B, ib00, jb00, N / 2);
    square_matrix_multiply_recursive(C, ic01, jc01, A, ia00, ja00, B, ib01, jb01, N / 2);
    square_matrix_multiply_recursive(C, ic10, jc10, A, ia10, ja10, B, ib00, jb00, N / 2);
    square_matrix_multiply_recursive(C, ic11, jc11, A, ia10, ja10, B, ib01, jb01, N / 2);
    square_matrix_multiply_recursive(T, it00, jt00, A, ia01, ja01, B, ib10, jb10, N / 2);
    square_matrix_multiply_recursive(T, it01, jt01, A, ia01, ja01, B, ib11, jb11, N / 2);
    square_matrix_multiply_recursive(T, it10, jt10, A, ia11, ja11, B, ib10, jb10, N / 2);
    square_matrix_multiply_recursive(T, it11, jt11, A, ia11, ja11, B, ib11, jb11, N / 2);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        C[ic + i][jc + j] += T[i][j];
      }
    }
  }
}

int main() {
  int N = 4;
  vector<vector<int>> A{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> B{{11, 12, 13, 14}, {15, 16, 17, 18}, {19, 20, 21, 22}, {23, 24, 25, 26}};
  vector<vector<int>> C(N, vector<int>(N, 0));

  square_matrix_multiply_recursive(C, 0, 0, A, 0, 0, B, 0, 0, N);

  printf("[");
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("[");
    for (int j = 0; j < N; ++j) {
      printf("%d, ", C[i][j]);
    }
    printf("]");
    if (i < N - 1) {
      printf("\n");
    }
  }
  printf("]\n");
}

// [[190, 200, 210, 220, ]
//  [462, 488, 514, 540, ]
//  [734, 776, 818, 860, ]
//  [1006, 1064, 1122, 1180, ]]