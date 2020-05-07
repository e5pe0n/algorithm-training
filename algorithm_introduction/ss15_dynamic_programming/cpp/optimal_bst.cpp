#include <limits>
#include <stdio.h>

using namespace std;

int F_MAX = numeric_limits<float>::max();

float e[7][6]{};
float w[7][6]{};
int root[7][6]{};

int d_num = 0;

void construct_optimal_bst(int root[][6], int i, int j, int p, int i_init, int j_init) {
  if (root[i][j] <= 0) {
    if (j < p) {
      printf("d%d is left child of k%d\n", d_num, p);
    } else {
      printf("d%d is right child of k%d\n", d_num, p);
    }
    ++d_num;
    return;
  }
  int r = root[i][j];
  if (i == i_init && j == j_init) {
    printf("k%d is root\n", r);
  } else if (j < p) {
    printf("k%d is left child of k%d\n", r, p);
  } else {
    printf("k%d is right child of k%d\n", r, p);
  }
  construct_optimal_bst(root, i, r - 1, r, i_init, j_init);
  construct_optimal_bst(root, r + 1, j, r, i_init, j_init);
}

void optimal_bst(float *p, float *q, float n, float e[][6], float w[][6]) {
  for (int i = 1; i <= n + 1; ++i) {
    e[i][i - 1] = q[i - 1];
    w[i][i - 1] = q[i - 1];
  }
  for (int l = 1; l <= n; ++l) {
    for (int i = 1; i <= n - l + 1; ++i) {
      int j = i + l - 1;
      e[i][j] = F_MAX;
      w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
      for (int r = i; r <= j; ++r) {
        float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
        if (t < e[i][j]) {
          e[i][j] = t;
          root[i][j] = r;
        }
      }
    }
  }
}

int main() {
  float p[]{0.15, 0.10, 0.05, 0.10, 0.20};
  float q[]{0.05, 0.10, 0.05, 0.05, 0.05, 0.10};

  optimal_bst(p, q, 5, e, w);

  construct_optimal_bst(root, 1, 5, 0, 1, 5);
}