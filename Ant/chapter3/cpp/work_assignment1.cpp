#include <algorithm>
#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define MAX_N 1000
#define MAX_M 1000
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int v, cap, rev;
};

int N, M, K;
vector<Edge> G[MAX_N + MAX_M + 2]; // 0..N-1:=computer, N..N+K-1:=work, N+K:=s, N+K+1:=t
bool used[MAX_N + MAX_M + 2];

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

int main() {
  ifstream ifs("../testset/work_assignment/test2.txt");
  ifs >> N >> M >> K;
  for (int i = 0; i < K; ++i) {
    int u, v;
    ifs >> u >> v;
    add_edge(u - 1, N + v - 1, 1);
  }
  int s = N + M;
  int t = s + 1;
  for (int i = 0; i < N; ++i) {
    add_edge(s, i, 1);
  }
  for (int i = 0; i < M; ++i) {
    add_edge(N + i, t, 1);
  }
  int res = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if (f == 0) {
      printf("%d\n", res);
      return 0;
    }
    res += f;
  }
}