#include <algorithm>
#include <iostream>
#include <stdio.h>

#define N 10
#define MAX_C 1000
#define MAX_H 200
#define MAX_W 200

using namespace std;

int dist[N]{};
int C[N][N]{};
int A[MAX_H][MAX_W]{};

void bellman_ford() {
  for (int i = 0; i < N; ++i) {
    dist[i] = MAX_C;
  }
  dist[1] = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int u = 0; u < N; ++u) {
      for (int v = 0; v < N; ++v) {
        dist[v] = min(dist[v], dist[u] + C[v][u]);
      }
    }
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> C[i][j];
    }
  }
  bellman_ford();
  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int a;
      cin >> a;
      if (a >= 0) {
        ans += dist[a];
      }
    }
  }
  printf("%d\n", ans);
}