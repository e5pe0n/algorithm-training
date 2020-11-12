#include <algorithm>
#include <fstream>
#include <memory.h>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAX_n 100
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int v, cap, rev;
};

int n, m, s, t;
vector<Edge> G[MAX_n];
int level[MAX_n];
int iter[MAX_n];

void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue<int> q;
  q.push(s);
  level[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto e : G[u]) {
      if (e.cap > 0 && level[e.v] < 0) {
        level[e.v] = level[u] + 1;
        q.push(e.v);
      }
    }
  }
}

int dfs(int u, int t, int f) {
  if (u == t) {
    return f;
  }
  for (int &i = iter[u]; i < G[u].size(); ++i) {
    Edge &e = G[u][i];
    if (e.cap > 0 && level[u] < level[e.v]) {
      int d = dfs(e.v, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.v][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int main() {
  ifstream ifs("../testset/maximum_traffic/test1.txt");
  ifs >> n >> m >> s >> t;
  for (int i = 0; i < m; ++i) {
    int u, v, cap;
    ifs >> u >> v >> cap;
    G[u].push_back(Edge{v, cap, G[v].size()});
    G[v].push_back(Edge{u, 0, G[u].size() - 1});
  }

  int res = 0;
  for (;;) {
    bfs(s);
    if (level[t] < 0) {
      printf("%d\n", res);
      return 0;
    }
    memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(s, t, INF)) > 0) {
      res += f;
    }
  }
}