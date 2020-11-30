#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define MAX_N 100
#define MAX_V MAX_N * 2
#define MAX_K 25

using namespace std;

int N, K, V;
int P[MAX_N][MAX_K];
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int u) {
  used[u] = true;
  for (auto v : G[u]) {
    int _u = match[v];
    if (_u < 0 || (!used[_u] && dfs(_u))) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  memset(match, -1, sizeof(match));
  for (int u = 0; u < N; ++u) {
    if (match[u] < 0) {
      memset(used, false, sizeof(used));
      if (dfs(u)) {
        ++res;
      }
    }
  }
  return res;
}

void solve() {
  V = N * 2;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) {
        continue;
      }
      bool f = true;
      for (int k = 0; k < K; ++k) {
        if (P[j][k] >= P[i][k]) {
          f = false;
          break;
        }
      }
      if (f) {
        add_edge(i, N + j);
      }
    }
  }
  printf("%d\n", N - bipartite_matching());
}

int main() {
  ifstream ifs("../testset/stock_charts/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      ifs >> P[i][j];
    }
  }
  solve();
}