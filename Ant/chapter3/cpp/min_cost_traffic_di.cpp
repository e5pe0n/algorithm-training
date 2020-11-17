#include <algorithm>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_N 1000
#define INF 1'000'000'000

using namespace std;

typedef pair<int, int> pii;

struct Edge {
  int v, cap, cost, rev;
};

int N, M, S, T, F;
vector<Edge> G[MAX_N];
int h[MAX_N], dist[MAX_N];
int prevv[MAX_N], preve[MAX_N];

int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h, h + N, 0);
  while (f > 0) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    fill(dist, dist + N, INF);
    dist[s] = 0;
    q.push(pii(0, s));
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
          q.push(pii(dist[e.v], e.v));
        }
      }
    }
    if (dist[t] == INF) {
      return -1;
    }
    for (int u = 0; u < N; ++u) {
      h[u] += dist[u]; // why add?
    }
    int d = f;
    for (int u = t; u != s; u = prevv[u]) {
      d = min(d, G[prevv[u]][preve[u]].cap);
    }
    f -= d;
    res += d * h[t]; // why h[t], not dist[t]?
    for (int u = t; u != s; u = prevv[u]) {
      Edge &e = G[prevv[u]][preve[u]];
      e.cap -= d;
      G[u][e.rev].cap += d;
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/min_cost_traffic/test1.txt");
  ifs >> N >> M >> S >> T >> F;
  for (int i = 0; i < M; ++i) {
    int u, v, cap, cost;
    ifs >> u >> v >> cap >> cost;
    G[u].push_back(Edge{v, cap, cost, G[v].size()});
    G[v].push_back(Edge{u, 0, -cost, G[u].size() - 1});
  }
  int res = min_cost_flow(S, T, F);
  printf("%d\n", res);
}