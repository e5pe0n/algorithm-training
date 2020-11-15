#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_N 1000
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int v, cap, cost, rev;
};

int N, M, S, T, F;
vector<Edge> G[MAX_N];
int dist[MAX_N];
int prevv[MAX_N], preve[MAX_N];

int min_cost_flow(int s, int t, int f) {
  // O(F|E||V|)
  int res = 0;
  while (f > 0) {
    fill(dist, dist + N, INF);
    dist[s] = 0;
    bool update = true;
    while (update) {
      update = false;
      for (int u = 0; u < N; ++u) {
        if (dist[u] == INF) {
          continue;
        }
        for (int i = 0; i < G[u].size(); ++i) {
          Edge &e = G[u][i];
          if (e.cap > 0 && dist[e.v] > dist[u] + e.cost) {
            dist[e.v] = dist[u] + e.cost;
            prevv[e.v] = u;
            preve[e.v] = i;
            update = true;
          }
        }
      }
    }
    if (dist[t] == INF) {
      return -1;
    }
    int d = f;
    for (int u = t; u != s; u = prevv[u]) {
      d = min(d, G[prevv[u]][preve[u]].cap);
    }
    f -= d;
    res += d * dist[t];
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