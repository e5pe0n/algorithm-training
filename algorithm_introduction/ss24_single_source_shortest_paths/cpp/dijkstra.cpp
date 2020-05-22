#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

#define INF 1'000'000'000
#define N 5

using namespace std;

struct Vertex {
  int n;
  int dist = INF;
  Vertex *pth = nullptr;
  vector<pair<Vertex *, int>> arrows;
  Vertex() {}
  Vertex(int n) : n(n) {}

  friend bool operator<(const Vertex &lhs, const Vertex &rhs) { return lhs.dist < rhs.dist; }
  friend bool operator>(const Vertex &lhs, const Vertex &rhs) { return lhs.dist > rhs.dist; }
};

Vertex V[N];
bool selected[N]{};

void initialize_single_source(Vertex V[]) { V[0].dist = 0; }

void relax(Vertex *u, Vertex *v, int weight) {
  if (v->dist > u->dist + weight) {
    v->dist = u->dist + weight;
    v->pth = u;
  }
}

void dijkstra(Vertex V[]) {
  priority_queue<Vertex, vector<Vertex>, greater<vector<Vertex>::value_type>> q;
  initialize_single_source(V);
  q.push(V[0]);
  while (!q.empty()) {
    Vertex u = q.top();
    q.pop();
    selected[u.n] = true;
    for (auto a : u.arrows) {
      if (!selected[a.first->n]) {
        relax(&u, a.first, a.second);
        q.push(*a.first);
      }
    }
  }
}

int main() {
  V[0] = Vertex(0);
  V[1] = Vertex(1);
  V[2] = Vertex(2);
  V[3] = Vertex(3);
  V[4] = Vertex(4);

  V[0].arrows = vector<pair<Vertex *, int>>{make_pair(&V[1], 10), make_pair(&V[3], 5)};
  V[1].arrows = vector<pair<Vertex *, int>>{make_pair(&V[2], 1), make_pair(&V[3], 2)};
  V[2].arrows = vector<pair<Vertex *, int>>{make_pair(&V[4], 4)};
  V[3].arrows = vector<pair<Vertex *, int>>{make_pair(&V[1], 3), make_pair(&V[2], 9), make_pair(&V[4], 2)};
  V[4].arrows = vector<pair<Vertex *, int>>{make_pair(&V[0], 7), make_pair(&V[2], 6)};

  dijkstra(V);

  for (int i = 0; i < N; ++i) {
    printf("V[%d].dist: %d\n", i, V[i].dist);
  }
}

// V[0].dist: 0
// V[1].dist: 8
// V[2].dist: 9
// V[3].dist: 5
// V[4].dist: 7