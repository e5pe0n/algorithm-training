#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

#define INF 1'000'000'000
#define S 6
#define R 4
#define C 4

float L[C]{};
float E[R]{};
int N[C]{};
int B[R]{};
float X[S];

float pivot(float A[][C], float v, int l, int e) {
  float a = 1 / A[l][e];
  for (int i = 0; i < R; ++i) {
    E[i] = A[i][e];
  }
  for (int j = 0; j < C; ++j) {
    L[j] = -A[l][j] * a;
  }
  L[e] = a;

  v += -A[l][C - 1] * a * A[R - 1][e];

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      A[i][j] += L[j] * E[i];
    }
    A[i][e] = E[i] * a;
  }
  for (int j = 0; j < C; ++j) {
    A[l][j] = L[j];
  }

  swap(B[l], N[e]);
  return v;
}

void initialize_simplex(float A[][C], int B[], int N[]) {
  for (int i = 0; i < C - 1; ++i) {
    N[i] = i;
  }
  for (int i = 0; i < R - 1; ++i) {
    B[i] = i + C - 1;
  }
}

float simplex(float A[][C], int B[], int N[]) {
  initialize_simplex(A, B, N);
  int e = -1;
  int l = -1;
  float v = A[R - 1][C - 1];
  while (true) {
    int positive_c_idx[C];
    int positive_c_cnt = 0;
    for (int j = 0; j < C - 1; ++j) {
      if (A[R - 1][j] > 0) {
        positive_c_idx[positive_c_cnt++] = j;
      }
    }
    if (positive_c_cnt == 0) {
      break;
    }
    float max_f_dlt = 0;
    for (int j = 0; j < positive_c_cnt; ++j) {
      float min_x_dlt = INF;
      int min_x_idx = -1;
      for (int i = 0; i < R - 1; ++i) {
        if (A[i][positive_c_idx[j]] < 0) {
          float x_dlt = -A[i][C - 1] / A[i][positive_c_idx[j]];
          if (x_dlt < min_x_dlt) {
            min_x_dlt = x_dlt;
            min_x_idx = i;
          }
        }
      }
      if (min_x_dlt > 0) {
        float f_dlt = A[R - 1][positive_c_idx[j]] * min_x_dlt;
        if (f_dlt > max_f_dlt) {
          max_f_dlt = f_dlt;
          l = min_x_idx;
          e = positive_c_idx[j];
        }
      }
    }
    if (e < 0) {
      throw "Not finite";
    } else {
      v = pivot(A, v, l, e);
    }
  }

  for (int k = 0; k < C - 1; ++k) {
    X[B[k]] = A[k][C - 1];
  }
  // for (int k = 0; k < R - 1; ++k) {
  //   X[N[k]] = 0;
  // }
  return v;
}

int main() {
  // float A[R][C] = {{-2, -8, 60}, {-4, -4, 60}, {29, 45, 0}};
  float A[R][C] = {
      {-1, -1, -3, 30},
      {-2, -2, -5, 24},
      {-4, -1, -2, 36},
      {3, 1, 2, 0},
  }; // A[R - 1][...] = c, A[...][C - 1] = b

  try {
    float res = simplex(A, B, N);
    printf("res: %3.f\n", res);
    for (int i = 0; i < S; ++i) {
      printf("x%d: %3.f\n", i, X[i]);
    }
    printf("\nA:\n");
    printf("[");
    for (int i = 0; i < R; ++i) {
      if (i > 0) {
        printf(" ");
      }
      printf("[");
      for (int j = 0; j < C; ++j) {
        printf("%6.3f, ", A[i][j]);
      }
      printf("]");
      if (i < R - 1) {
        printf("\n");
      }
    }
    printf("]\n");
  } catch (const char *e) {
    printf("%s\n", e);
  }
}

// res:  28
// x0:   8
// x1:   4
// x2:   0
// x3:  18
// x4:   0
// x5:   0

// A:
// [[ 0.000,  0.500, -0.500, 18.000, ]
//  [ 0.333, -0.667, -2.667,  4.000, ]
//  [-0.333,  0.167,  0.167,  8.000, ]
//  [-0.667, -0.167, -0.167, 28.000, ]]