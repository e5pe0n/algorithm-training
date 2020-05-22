#include <algorithm>
#include <math.h>
#include <stdio.h>

#define INF 1'000'000'000
#define N 5

using namespace std;

int L[N - 1][N][N];
int W[N][N];

void extend_shortest_paths(int _L[][N], int W[][N], int m) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      L[m][i][j] = INF;
      for (int k = 0; k < N; ++k) {
        L[m][i][j] = min(L[m][i][j], _L[i][k] + W[k][j]);
      }
    }
  }
}

void faster_all_pairs_shortest_paths(int L[][N][N], int W[][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      L[0][i][j] = W[i][j];
    }
  }
  int idx = 0;
  int m = 1;
  while (m < N - 1) {
    extend_shortest_paths(L[idx], L[idx], idx + 1);
    ++idx;
    m *= 2;
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

  faster_all_pairs_shortest_paths(L, W);

  int last_idx = int(log2(N - 1));
  for (int m = 0; m <= last_idx; ++m) {
    printf("m: %d\n", m);
    print_matrix(L[m]);
    printf("\n");
  }
}