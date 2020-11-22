#include <fstream>
#include <stdio.h>

#define INF 1'000'000'000
#define MAX_N 100
#define MAX_M 100
#define MAX_V MAX_N + MAX_M + 1

using namespace std;

int N, M, V;
int X[MAX_N], Y[MAX_N], B[MAX_N];
int P[MAX_M], Q[MAX_M], C[MAX_M];
int E[MAX_N][MAX_M];

int g[MAX_V][MAX_V];
int prv[MAX_V][MAX_V];
bool used[MAX_V];

void solve() {
  V = N + M + 1;
  for (int i = 0; i < V; ++i) {
    fill(g[i], g[i] + V, INF);
  }
  for (int j = 0; j < M; ++j) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
      g[i][N + j] = c;
      if (E[i][j] > 0) {
        g[N + j][i] = -c;
      }
      sum += E[i][j];
    }
    if (sum > 0) {
      g[N + M][N + j] = 0; // can return people from colony_j without cost
    }
    if (sum < C[j]) {
      g[N + j][N + M] = 0; // can accommodate people more
    }
  }
  // detect a negative loop by the Warshall-Floyd algorithm
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      prv[i][j] = i;
    }
  }
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (g[i][j] > g[i][k] + g[k][j]) {
          g[i][j] = g[i][k] + g[k][j];
          prv[i][j] = prv[k][j];
          if (i == j && g[i][j] < 0) {
            fill(used, used + V, false);
            for (int u = i; !used[u]; u = prv[i][u]) {
              used[u] = true;
              if (u != N + M && prv[i][u] != N + M) {
                if (u >= N) {
                  ++E[prv[i][u]][u - N];
                } else {
                  --E[u][prv[i][u] - N];
                }
              }
            }
            printf("SUBOPTIMAL\n");
            for (int x = 0; x < N; ++x) {
              for (int y = 0; y < M; ++y) {
                printf("%d%c", E[x][y], y == M - 1 ? '\n' : ' ');
              }
            }
            return;
          }
        }
      }
    }
  }
  printf("OPTIMAL\n");
}

int main() {
  ifstream ifs("../testset/evacuation_plan/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    ifs >> X[i] >> Y[i] >> B[i];
  }
  for (int i = 0; i < M; ++i) {
    ifs >> P[i] >> Q[i] >> C[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      ifs >> E[i][j];
    }
  }
  solve();
}