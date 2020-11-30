// O(F|E|)
#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define MAX_N 100
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int v, cap, rev;
};

int n, m, s, t;
vector<Edge> G[MAX_N];
bool used[MAX_N];

void add_edge(int u, int v, int cap) {
  G[u].push_back(Edge{v, cap, G[v].size()});
  G[v].push_back(Edge{u, 0, G[u].size() - 1});
}

int dfs(int u, int t, int f) {
  if (u == t) {
    return f;
  }
  used[u] = true;
  for (int i = 0; i < G[u].size(); ++i) {
    Edge &e = G[u][i];
    if (!used[e.v] && e.cap > 0) {
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

int max_flow(int s, int t) {
  int res = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if (f == 0) {
      return res;
    }
    res += f;
  }
}

void solve() {
  int res = max_flow(s, t);
  printf("%d\n", res);
}

int main() {
  ifstream ifs("../testset/maximum_traffic/test1.txt");
  ifs >> n >> m >> s >> t;
  for (int i = 0; i < m; ++i) {
    int u, v, cap;
    ifs >> u >> v >> cap;
    add_edge(u, v, cap);
  }
  solve();
}