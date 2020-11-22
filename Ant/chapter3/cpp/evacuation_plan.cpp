#include <algorithm>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <vector>

#define INF 1'000'000'000
#define MAX_N 100
#define MAX_M 100
#define MAX_V MAX_N + MAX_M + 2

using namespace std;
typedef pair<int, int> pii;

struct Edge {
  int v, cap, cost, rev;
};

int N, M, V;
int X[MAX_N], Y[MAX_N], B[MAX_N];
int P[MAX_M], Q[MAX_M], C[MAX_M];
int E[MAX_N][MAX_M];

vector<Edge> G[MAX_V];
int prevv[MAX_V], preve[MAX_V];
int h[MAX_V], dist[MAX_V];

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
      if (p.first > dist[u]) {
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
  int s = N + M;
  int t = s + 1;
  V = t + 1;
  int cost = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
      add_edge(i, N + j, INF, c);
      cost += E[i][j] * c;
    }
  }
  int F = 0;
  for (int i = 0; i < N; ++i) {
    add_edge(s, i, B[i], 0);
    F += B[i];
  }
  for (int i = 0; i < M; ++i) {
    add_edge(N + i, t, C[i], 0);
  }
  if (min_cost_flow(s, t, F) < cost) {
    printf("SUBOPTIMAL\n");
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        printf("%d%c", G[N + j][i].cap, j == M - 1 ? '\n' : ' ');
      }
    }
  } else {
    printf("OPTIMAL\n");
  }
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