#include <algorithm>
#include <limits>
#include <stdio.h>

using namespace std;

int I_MAX = numeric_limits<int>::max();

int m[10][10]{};
int s[10][10]{};

void matrix_chain_order(int *p, int p_length) {
  int n = p_length - 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      m[i][j] = I_MAX;
    }
  }
  for (int i = 0; i <= n; ++i) {
    m[i][i] = 0;
  }
  for (int l = 2; l <= n; ++l) {
    for (int i = 1; i <= n - l + 1; ++i) {
      int j = i + l - 1;
      for (int k = i; k <= j - 1; ++k) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
}

void print_optimal_parser(int s[][10], int i, int j) {
  if (i == j)
    printf("A%d", i);
  else {
    printf("(");
    print_optimal_parser(s, i, s[i][j]);
    print_optimal_parser(s, s[i][j] + 1, j);
    printf(")");
  }
}

int main() {
  int p[]{30, 35, 15, 5, 10, 20, 25};
  matrix_chain_order(p, sizeof(p) / sizeof(p[0]));
  print_optimal_parser(s, 1, 6); // ((A_1(A_2A_3))((A_4A_5)A_6))
  printf("\n");
}