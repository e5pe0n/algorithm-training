#include <chrono>
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
  int n[] = {100, 200, 400, 800, 1600};
  for (int i = 0; i < 5; ++i) {
    int N = n[i];
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 1));
    vector<vector<int>> C(N, vector<int>(N, 0));

    auto start = chrono::high_resolution_clock::now();
    square_matrix_multiply_recursive(C, 0, 0, A, 0, 0, B, 0, 0, N);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    printf("N: %d, duration[ms]: %lld\n", N, duration);
  }
}

// N: 100, duration[ms]: 125
// N: 200, duration[ms]: 954
// N: 400, duration[ms]: 7624
// N: 800, duration[ms]: 59211
// N: 1600, duration[ms]: 482819