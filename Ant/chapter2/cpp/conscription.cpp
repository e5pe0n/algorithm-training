#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 10000
#define MAX_R 50000

using namespace std;

struct Edge {
  int u, v, weight;
};

int N, M, R;
Edge E[MAX_R];
int par[MAX_N * 2], rnk[MAX_N * 2]{};

void init() {
  for (int i = 0; i < N + M; ++i) {
    par[i] = i;
  }
}

int find(int u) {
  if (par[u] == u) {
    return u;
  }
  return par[u] = find(par[u]);
}

void unite(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    return;
  }
  if (rnk[u] < rnk[v]) {
    par[u] = v;
  } else {
    par[v] = u;
    if (rnk[u] == rnk[v]) {
      ++rnk[u];
    }
  }
}

bool same(int u, int v) { return find(u) == find(v); }

int kruscal() {
  init();
  sort(E, E + R, [](const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; });
  int res = 0;
  for (auto e : E) {
    if (!same(e.u, e.v)) {
      res += e.weight;
      unite(e.u, e.v);
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/conscription/test1.txt");
  ifs >> N >> M >> R;
  for (int i = 0; i < R; ++i) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    E[i] = Edge{u, v + N, -weight};
  }
  int ans = 10000 * (N + M) + kruscal();
  printf("%d\n", ans);
}