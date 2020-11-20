#include <algorithm>
#include <fstream>
#include <memory.h>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAX_N 20'000
#define MAX_M 200'000
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int v, cap, rev;
};

int N, M;
int A[MAX_N], B[MAX_N];
int a[MAX_M], b[MAX_M], w[MAX_M];
vector<Edge> G[MAX_N + 2];
int level[MAX_N + 2];
int iter[MAX_N + 2];

void add_edge(int u, int v, int cap) {
  G[u].push_back(Edge{v, cap, G[v].size()});
  G[v].push_back(Edge{u, 0, G[u].size() - 1});
}

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
    if (e.cap && level[e.v] > level[u]) {
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
    bfs(s);
    if (level[t] < 0) {
      return res;
    }
    memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(s, t, INF)) > 0) {
      res += f;
    }
  }
}

void solve() {
  int s = N;
  int t = s + 1;
  for (int i = 0; i < N; ++i) {
    add_edge(s, i, B[i]);
    add_edge(i, t, A[i]);
  }
  for (int i = 0; i < M; ++i) {
    add_edge(a[i], b[i], w[i]);
    add_edge(b[i], a[i], w[i]);
  }
  printf("%d\n", max_flow(s, t));
}

int main() {
  ifstream ifs("../testset/dual_core_cpu/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i] >> B[i];
  }
  for (int i = 0; i < M; ++i) {
    ifs >> a[i] >> b[i] >> w[i];
    --a[i];
    --b[i];
  }
  solve();
}