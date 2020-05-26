#include <queue>
#include <stdio.h>
#include <vector>

#define INF 1'000'000'000
#define N 5

using namespace std;

int h[N + 1];
int D[N + 1][N + 1];
bool selected[N + 1];

struct Edge {
  int u;
  int v;
  int weight;
};

struct Vertex {
  int n;
  int d;
  friend bool operator<(const Vertex &lhs, const Vertex &rhs) { return lhs.d < rhs.d; }
  friend bool operator>(const Vertex &lhs, const Vertex &rhs) { return lhs.d > rhs.d; }
};

void init() {
  for (int i = 0; i <= N; ++i) {
    h[i] = INF;
  }
  h[0] = 0;

  for (int i = 1; i < N; ++i) {
    for (int j = 2; j < N; ++j) {
      D[i][j] = INF;
    }
  }
  for (int i = 1; i < N; ++i) {
    D[i][1] = 0;
  }
}

int relax(int u, int v, int weight, int a[]) {
  if (a[u] < INF && a[v] > a[u] + weight) {
    a[v] = a[u] + weight;
  }
  return a[v];
}

bool bellman_ford(vector<Edge> E[]) {
  for (int i = 0; i < N; ++i) {
    for (int i = 0; i <= N; ++i) {
      for (auto e : E[i]) {
        relax(e.u, e.v, e.weight, h);
      }
    }
  }
  for (int i = 0; i <= N; ++i) {
    for (auto e : E[i]) {
      if (h[e.v] > h[e.u] + e.weight) {
        return false;
      }
    }
  }
  return true;
}

void dijkstra(vector<Edge> E[], Vertex V[], int k) {
  priority_queue<Vertex, vector<Vertex>, greater<vector<Vertex>::value_type>> q;
  q.push(V[k]);
  while (!q.empty()) {
    Vertex u = q.top();
    q.pop();
    selected[u.n] = true;
    for (auto e : E[u.n]) {
      if (!selected[e.v]) {
        V[e.v].d = relax(u.n, e.v, e.weight, D[k]);
        q.push(V[e.v]);
      }
    }
  }
}

bool johnson(vector<Edge> E[], Vertex V[]) {
  init();
  bool has_no_loop = bellman_ford(E);
  if (!has_no_loop) {
    return false;
  }
  for (int i = 1; i <= N; ++i) {
    for (auto e : E[i]) {
      e.weight = e.weight + h[e.u] - h[e.v];
    }
  }
  for (int i = 1; i <= N; ++i) {
    Vertex _V[N + 1];
    for (int j = 1; j <= N; ++j) {
      _V[j] = V[i];
      selected[j] = false;
    }
    dijkstra(E, _V, i);
  }
  for (int u = 1; u <= N; ++u) {
    for (int v = 1; v <= N; ++v) {
      D[u][v] = D[u][v] + h[v] - h[u];
    }
  }
  return true;
}

int main() {
  vector<Edge> E[] = {vector<Edge>{Edge{0, 1, 0}, Edge{0, 2, 0}, Edge{0, 3, 0}, Edge{0, 4, 0}, Edge{0, 5, 0}},
                      vector<Edge>{Edge{1, 2, 3}, Edge{1, 3, 8}, Edge{1, 5, -4}},
                      vector<Edge>{Edge{2, 4, 1}, Edge{2, 5, 7}},
                      vector<Edge>{Edge{3, 2, 4}},
                      vector<Edge>{Edge{4, 1, 2}},
                      vector<Edge>{Edge{5, 4, 6}}};

  Vertex V[] = {Vertex{0, 0}, Vertex{1, 0}, Vertex{2, -1}, Vertex{3, -5}, Vertex{4, 0}, Vertex{5, -4}};

  bool has_no_loop = johnson(E, V);
  if (has_no_loop) {
    for (int i = 1; i <= N; ++i) {
      if (i > 1) {
        printf(" ");
      }
      printf("[");
      for (int j = 1; j <= N; ++j) {
        printf("%d, ", D[i][j]);
      }
      printf("]");
      if (i < N) {
        printf("\n");
      }
    }
    printf("]\n");
  } else {
    printf("Found a loop");
  }
}
