#include <algorithm>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <vector>
#define INF 1'000'000'000
#define MAX_N 50
#define MAX_M 50
#define MAX_V (MAX_M + 1) * MAX_N + 2
using namespace std;
typedef pair<int, int> pii;

struct Edge {
  int v, cap, cost, rev;
};

int N, M, V;
int Z[MAX_N][MAX_M];
vector<Edge> G[MAX_V];
int h[MAX_V], dist[MAX_V], prevv[MAX_V], preve[MAX_V];

void add_edge(int u, int v, int cap, int cost) {
  G[u].push_back(Edge{v, cap, cost, G[v].size()});
  G[v].push_back(Edge{u, 0, -cost, G[u].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h, h + V, 0);
  while (f > 0) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
      pii p = q.top();
      q.pop();
      int u = p.second;
      if (dist[u] < p.first) {
        continue;
      }
      for (int i = 0; i < G[u].size(); ++i) {
        Edge &e = G[u][i];
        if (e.cap > 0 && dist[e.v] > dist[u] + e.cost + h[u] - h[e.v]) {
          dist[e.v] = dist[u] + e.cost + h[u] - h[e.v];
          prevv[e.v] = u;
          preve[e.v] = i;
          q.push({dist[e.v], e.v});
        }
      }
    }
    if (dist[t] == INF) {
      return -1;
    }
    for (int u = 0; u < V; ++u) {
      h[u] += dist[u];
    }
    int d = f;
    for (int u = t; u != s; u = prevv[u]) {
      d = min(d, G[prevv[u]][preve[u]].cap);
    }
    f -= d;
    res += d * h[t];
    for (int u = t; u != s; u = prevv[u]) {
      Edge &e = G[prevv[u]][preve[u]];
      e.cap -= d;
      G[u][e.rev].cap += d;
    }
  }
  return res;
}

void solve() {
  // 0..N-1: toys
  // N..2N-1: 0th factory
  // 2N..3N-1: 1st factory
  // ...
  // MN - (M+1)N-1: (M-1)th factory
  int s = (M + 1) * N;
  int t = s + 1;
  V = t + 1;
  for (int i = 0; i < N; ++i) {
    add_edge(s, i, 1, 0);
  }
  for (int j = 0; j < M; ++j) {
    for (int k = 0; k < N; ++k) {
      add_edge(N + j * N + k, t, 1, 0);
      for (int i = 0; i < N; ++i) {
        add_edge(i, N + j * N + k, 1, (k + 1) * Z[i][j]);
      }
    }
  }
  printf("%.6f\n", (double)min_cost_flow(s, t, N) / N);
}

int main() {
  ifstream ifs("../testset/the_windys/test3.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      ifs >> Z[i][j];
    }
  }
  solve();
}