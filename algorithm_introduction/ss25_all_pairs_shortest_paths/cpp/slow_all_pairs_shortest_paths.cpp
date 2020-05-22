#include <algorithm>
#include <stdio.h>

#define INF 1'000'000'000
#define N 5

using namespace std;

int L[N - 1][N][N];
int W[N][N];

void extend_shortest_paths(int L[][N][N], int W[][N], int m) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      L[m][i][j] = INF;
      for (int k = 0; k < N; ++k) {
        L[m][i][j] = min(L[m][i][j], L[m - 1][i][k] + W[k][j]);
      }
    }
  }
}

void slow_all_pairs_shortest_paths(int L[][N][N], int W[][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      L[0][i][j] = W[i][j];
    }
  }
  for (int m = 1; m < N - 1; ++m) {
    extend_shortest_paths(L, W, m);
  }
}

void print_matrix(int M[][N]) {
  printf("[");
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("[");
    for (int j = 0; j < N; ++j) {
      printf("%3d, ", M[i][j]);
    }
    printf("]");
    if (i < N - 1) {
      printf("\n");
    }
  }
  printf("]\n");
}

int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) {
        W[i][j] = 0;
      } else {
        W[i][j] = INF;
      }
    }
  }

  W[0][1] = 3;
  W[0][2] = 8;
  W[0][4] = -4;
  W[1][3] = 1;
  W[1][4] = 7;
  W[2][1] = 4;
  W[3][2] = -5;
  W[3][0] = 2;
  W[4][3] = 6;

  slow_all_pairs_shortest_paths(L, W);

  for (int m = 0; m < N - 1; ++m) {
    printf("m: %d\n", m);
    print_matrix(L[m]);
    printf("\n");
  }
}

// m: 0
// [[  0,   3,   8, 1000000000,  -4, ]
//  [1000000000,   0, 1000000000,   1,   7, ]
//  [1000000000,   4,   0, 1000000000, 1000000000, ]
//  [  2, 1000000000,  -5,   0, 1000000000, ]
//  [1000000000, 1000000000, 1000000000,   6,   0, ]]

// m: 1
// [[  0,   3,   8,   2,  -4, ]
//  [  3,   0,  -4,   1,   7, ]
//  [1000000000,   4,   0,   5,  11, ]
//  [  2,  -1,  -5,   0,  -2, ]
//  [  8, 1000000000,   1,   6,   0, ]]

// m: 2
// [[  0,   3,  -3,   2,  -4, ]
//  [  3,   0,  -4,   1,  -1, ]
//  [  7,   4,   0,   5,  11, ]
//  [  2,  -1,  -5,   0,  -2, ]
//  [  8,   5,   1,   6,   0, ]]

// m: 3
// [[  0,   1,  -3,   2,  -4, ]
//  [  3,   0,  -4,   1,  -1, ]
//  [  7,   4,   0,   5,   3, ]
//  [  2,  -1,  -5,   0,  -2, ]
//  [  8,   5,   1,   6,   0, ]]