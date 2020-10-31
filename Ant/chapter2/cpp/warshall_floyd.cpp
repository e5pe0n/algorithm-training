#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdio.h>

#define MAX_N 1'000
#define INF 1'000'000'000

using namespace std;

int N, K;
int d[MAX_N][MAX_N];

void warshall_floyd() {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  ifstream ifs("../testset/all_pairs_shortest_path/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = INF;
      }
    }
  }
  for (int i = 0; i < K; ++i) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    --u;
    --v;
    d[u][v] = weight;
    // if non-direction graph add d[v][u]
    // d[v][u] = weight;
  }
  warshall_floyd();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}

// 0 1 -3 2 -4
// 3 0 -4 1 -1
// 7 4 0 5 3
// 2 -1 -5 0 -2
// 8 5 1 6 0