#include <algorithm>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <vector>

#define INF 1'000'000'000
#define MAX_N 1000
#define MAX_M 10'000

using namespace std;
typedef pair<int, int> pii;

struct Edge {
  int v, cap, cost, rev;
};

int N, M;
int a[MAX_M], b[MAX_M], c[MAX_M];
vector<Edge> G[MAX_N];
int h[MAX_N], dist[MAX_N];
int prevv[MAX_N], preve[MAX_N];

void add_edge(int u, int v, int cap, int cost) {
  G[u].push_back(Edge{v, cap, cost, G[v].size()});
  G[v].push_back(Edge{u, 0, -cost, G[u].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h, h + N, 0);
  while (f > 0) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    fill(dist, dist + N, INF);
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
    for (int u = 0; u < N; ++u) {
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
  for (int i = 0; i < M; ++i) {
    add_edge(a[i], b[i], 1, c[i]);
  }
  printf("%d\n", min_cost_flow(0, N - 1, 2));
}

int main() {
  ifstream ifs("../testset/farm_tour/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < M; ++i) {
    ifs >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
  }
  solve();
}