#include <stdio.h>
#include <vector>

using namespace std;

int N = 6;
vector<int> V[6];
int p[6];
int d[6]{};
int f[6]{};
int time;

void dfs(vector<int> *V, int N, int *p, int *d, int *f) {
  memset(p, -1, N);
  time = 0;
  for (int u = 0; u < N; ++u) {
    if (d[u <= 0]) {
      dfs_visit(V, u, p, d, f);
    }
  }
}

void dfs_visit(vector<int> *V, int u, int *p, int *d, int *f) {
  d[u] = ++time;
  for (int i = 0; i < V[u].size(); ++i) {
    int v = V[u][i];
    if (d[v] <= 0) {
      p[v] = u;
      dfs_visit(V, v, p, d, f);
    }
  }
  f[u] = ++time;
}

int main() {
  V[0] = vector<int>{1, 3};
  V[1] = vector<int>{4};
  V[2] = vector<int>{4, 5};
  V[3] = vector<int>{1};
  V[4] = vector<int>{3};
  V[5] = vector<int>{5};

  dfs(V, N, p, d, f);
}