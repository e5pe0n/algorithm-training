#include <set>
#include <stdio.h>
#include <utility>

#define INF 1'000'000'000
#define N 4

using namespace std;

bool T[N + 1][N][N]{};

void transitive_closure(set<pair<int, int>> E) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      T[0][i][j] = i == j || E.find(make_pair(i, j)) != E.end();
    }
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        T[k][i][j] = T[k - 1][i][j] || (T[k - 1][i][k - 1] && T[k - 1][k - 1][j]);
      }
    }
  }
}

void print_matrix(bool M[N][N]) {
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
  set<pair<int, int>> E{make_pair(3, 0), make_pair(3, 2), make_pair(1, 3), make_pair(1, 2), make_pair(2, 1)};

  transitive_closure(E);

  for (int k = 0; k <= N; ++k) {
    printf("k: %d\n", k);
    print_matrix(T[k]);
    printf("\n");
  }
}

// k: 0
// [[  1,   0,   0,   0, ]
//  [  0,   1,   1,   1, ]
//  [  0,   1,   1,   0, ]
//  [  1,   0,   1,   1, ]]

// k: 1
// [[  1,   0,   0,   0, ]
//  [  0,   1,   1,   1, ]
//  [  0,   1,   1,   0, ]
//  [  1,   0,   1,   1, ]]

// k: 2
// [[  1,   0,   0,   0, ]
//  [  0,   1,   1,   1, ]
//  [  0,   1,   1,   1, ]
//  [  1,   0,   1,   1, ]]

// k: 3
// [[  1,   0,   0,   0, ]
//  [  0,   1,   1,   1, ]
//  [  0,   1,   1,   1, ]
//  [  1,   1,   1,   1, ]]

// k: 4
// [[  1,   0,   0,   0, ]
//  [  1,   1,   1,   1, ]
//  [  1,   1,   1,   1, ]
//  [  1,   1,   1,   1, ]]