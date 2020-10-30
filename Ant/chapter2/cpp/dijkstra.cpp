#include <fstream>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAX_N 10'000
#define MAX_K 10'000
#define INF 1'000'000'000

using namespace std;

typedef pair<int, int> P;

struct Edge {
  int u, v, weight;
  Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

int N, K, S, T;
vector<Edge> G[MAX_N];
int dist[MAX_N], path[MAX_N];

void init(int s) {
  fill(dist, dist + N, INF);
  fill(path, path + N, -1);
  dist[s] = 0;
}

void dijkstra(int s) {
  init(s);
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(P(0, s));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int u = p.second;
    if (dist[u] < p.first) {
      continue;
    }
    for (auto e : G[u]) {
      if (dist[e.v] > dist[u] + e.weight) {
        // relax
        dist[e.v] = dist[u] + e.weight;
        path[e.v] = u;
        q.push(P(dist[e.v], e.v));
      }
    }
  }
}

void _print_path(int s, int v) {
  if (s == v) {
    printf("%d", s + 1);
  } else if (v < 0) {
    printf("No path\n");
  } else {
    _print_path(s, path[v]);
    printf("->%d", v + 1);
  }
}

void print_path(int s, int v) {
  _print_path(s, v);
  printf("\n");
}

int main() {
  ifstream ifs("../testset/single_source_shortest_path/test1.txt");
  ifs >> N >> K >> S >> T;
  --S;
  --T;
  for (int i = 0; i < K; ++i) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    --u;
    --v;
    G[u].emplace_back(u, v, weight);
    G[v].emplace_back(v, u, weight);
  }
  dijkstra(S);
  printf("shortest distance=%d\n", dist[T]);
  printf("shortest path=");
  print_path(S, T);
}

// shortest distance=16
// shortest path=1->3->4->6->5->7