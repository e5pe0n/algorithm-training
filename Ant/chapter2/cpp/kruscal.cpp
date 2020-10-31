#include <algorithm>
#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_N 10'000
#define MAX_K 10'000

using namespace std;

struct Edge {
  int u, v, weight;
};

int N, K, ans;
int par[MAX_N], rnk[MAX_N]{};
Edge E[MAX_K];

void init() {
  for (int i = 0; i < N; ++i) {
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
  int res = 0;
  sort(E, E + K, [](const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; });
  init();
  for (auto e : E) {
    if (!same(e.u, e.v)) {
      res += e.weight;
      unite(e.u, e.v);
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/minimum_spanning_tree/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < K; ++i) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    E[i] = Edge{--u, --v, weight};
  }
  ans = kruscal();
  printf("%d\n", ans);
}