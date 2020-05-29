#include <chrono>
#include <future>
#include <stdio.h>
#include <vector>

using namespace std;

void p_matrix_multiply_recursive(vector<vector<int>> &C, int ic, int jc, vector<vector<int>> &A, int ia,
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

    vector<future<void>> futures;
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(C), ic00, jc00, ref(A), ia00, ja00, ref(B),
                               ib00, jb00, N / 2));
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(C), ic01, jc01, ref(A), ia00, ja00, ref(B),
                               ib01, jb01, N / 2));
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(C), ic10, jc10, ref(A), ia10, ja10, ref(B),
                               ib00, jb00, N / 2));
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(C), ic11, jc11, ref(A), ia10, ja10, ref(B),
                               ib01, jb01, N / 2));
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(T), it00, jt00, ref(A), ia01, ja01, ref(B),
                               ib10, jb10, N / 2));
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(T), it01, jt01, ref(A), ia01, ja01, ref(B),
                               ib11, jb11, N / 2));
    futures.emplace_back(async(p_matrix_multiply_recursive, ref(T), it10, jt10, ref(A), ia11, ja11, ref(B),
                               ib10, jb10, N / 2));
    p_matrix_multiply_recursive(ref(T), it11, jt11, ref(A), ia11, ja11, ref(B), ib11, jb11, N / 2);

    for (int i = 0; i < 7; ++i) {
      futures[i].get();
    }

    vector<future<void>> futures2;
    for (int i = 0; i < N; ++i) {
      futures2.emplace_back(async([i, &ic, &jc, &N, &C, &T] {
        vector<future<void>> futures3;
        for (int j = 0; j < N; ++j) {
          futures3.emplace_back(async([i, j, &ic, &jc, &C, &T] { C[ic + i][jc + j] += T[i][j]; }));
        }
        for (int j = 0; j < N; ++j) {
          futures3[j].get();
        }
      }));
    }
    for (int i = 0; i < N; ++i) {
      futures2[i].get();
    }
  }
}

int main() {
  int n[] = {10, 20, 40, 80, 160};
  for (int i = 0; i < 5; ++i) {
    int N = n[i];
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 1));
    vector<vector<int>> C(N, vector<int>(N, 0));

    auto start = chrono::high_resolution_clock::now();
    p_matrix_multiply_recursive(ref(C), 0, 0, ref(A), 0, 0, ref(B), 0, 0, N);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    printf("N: %d, duration: %lld\n", N, duration);
  }
}

// N: 10, duration: 21532
// N: 20, duration: 317805
// N: 40, duration: 15209098
// N: 80, didn't come back...
