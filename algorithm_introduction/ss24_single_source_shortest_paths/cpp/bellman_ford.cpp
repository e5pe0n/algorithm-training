#include <stdio.h>
#include <vector>

using namespace std;

#define N 5
#define INF 1'000'000'000

struct Edge {
  int u;
  int v;
  int weight;
};

int dist[N];
int pth[N];
vector<Edge> E;

void initialize_single_source() {
  for (int i = 0; i < N; ++i) {
    dist[i] = INF;
    pth[i] = -1;
  }
  dist[0] = 0;
}

void relax(int u, int v, int weight) {
  if (dist[v] > dist[u] + weight) {
    dist[v] = dist[u] + weight;
    pth[v] = u;
  }
}

bool bellman_ford(vector<Edge> &E) {
  initialize_single_source();
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

void print_path(int pth[], int s, int v) {
  if (s == v) {
    printf("%d", s);
  } else if (v < 0) {
    printf("\nPath from %d to %d does not exist.\n", s, v);
  } else {
    print_path(pth, s, pth[v]);
    printf("->%d", v);
  }
}

int main() {
  vector<Edge> E{Edge{0, 1, 6},  Edge{0, 3, 7},  Edge{1, 2, 5}, Edge{1, 3, 8}, Edge{1, 4, -4},
                 Edge{2, 1, -2}, Edge{3, 2, -3}, Edge{3, 4, 9}, Edge{4, 0, 2}, Edge{4, 2, 7}};

  bool has_no_loop = bellman_ford(E);
  printf("\n");
  if (has_no_loop) {
    print_path(pth, 0, 4);
    printf("\n");
  } else {
    printf("Found a loop.\n");
  }
}

// 0->3->2->1->4