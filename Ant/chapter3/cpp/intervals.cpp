#include <algorithm>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <tuple>
#include <vector>

#define INF 1'000'000'000
#define MAX_N 200
#define MAX_V MAX_N * 2 + 2

using namespace std;
typedef pair<int, int> pii;

struct Edge {
  int v, cap, cost, rev;
};

int N, K, V;
int a[MAX_N], b[MAX_N], w[MAX_N];
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
    priority_queue<pii> q;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    q.push({dist[s], s});
    while (!q.empty()) {
      int d, u;
      tie(d, u) = q.top();
      q.pop();
      if (dist[u] < d) {
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
  vector<int> x;
  for (int i = 0; i < N; ++i) {
    x.push_back(a[i]);
    x.push_back(b[i]);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());

  int m = x.size();
  int s = m;
  int t = s + 1;
  V = t + 1;
  add_edge(s, 0, K, 0);
  add_edge(m - 1, t, K, 0);
  for (int i = 0; i + 1 < m; ++i) {
    add_edge(i, i + 1, INF, 0);
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int u = find(x.begin(), x.end(), a[i]) - x.begin();
    int v = find(x.begin(), x.end(), b[i]) - x.begin();
    add_edge(v, u, 1, w[i]);
    add_edge(s, v, 1, 0);
    add_edge(u, t, 1, 0);
    res -= w[i];
  }
  res += min_cost_flow(s, t, K + N);
  printf("%d\n", -res);
}

int main() {
  ifstream ifs("../testset/intervals/test3.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    ifs >> a[i] >> b[i] >> w[i];
  }
  solve();
}