#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_N 10'000
#define MAX_K 10'000
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int u, v, weight;
};

int N, K, S, T;
int dist[MAX_N], path[MAX_N];
Edge E[MAX_K];

void init(int s) {
  fill(dist, dist + N, INF);
  fill(path, path + N, -1);
  dist[s] = 0;
}

void relax(int u, int v, int weight) {
  if (dist[v] > dist[u] + weight) {
    dist[v] = dist[u] + weight;
    path[v] = u;
  }
}

bool bellman_ford(int s) {
  init(s);

  // return false if the graph has negative loops.
  for (int i = 0; i < N - 1; ++i) {
    for (auto e : E) {
      relax(e.u, e.v, e.weight);
    }
  }
  for (auto e : E) {
    if (dist[e.v] > dist[e.u] + e.weight) {
      return false;
    }
  }
  return true;
}

void _print_path(int s, int v) {
  if (s == v) {
    printf("%d", s + 1);
  } else if (v < 0) {
    printf("\nNo path");
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
  for (int i = 0; i < K * 2; i += 2) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    --u;
    --v;
    E[i] = Edge{u, v, weight};
    E[i + 1] = Edge{v, u, weight};
  }
  if (bellman_ford(S)) {
    printf("dist=%d\n", dist[T]);
    printf("path=");
    print_path(S, T);
  } else {
    printf("detect negative loop\n");
  }
}

// dist=16
// path=1->3->4->6->5->7