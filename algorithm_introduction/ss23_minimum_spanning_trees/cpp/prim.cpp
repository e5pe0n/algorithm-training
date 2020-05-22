#include <limits>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

const int I_MAX = numeric_limits<int>::max();

struct Vertex {
  int n;
  int distance = I_MAX;
  vector<Vertex *> adj;
  int pth;
  Vertex() {}
  Vertex(int n) : n(n) {}
  friend bool operator<(const Vertex &left, const Vertex &right) { return left.distance < right.distance; }
  friend bool operator>(const Vertex &left, const Vertex &right) { return left.distance > right.distance; }
};

int N = 9;
Vertex V[100];
int weight[100][100];
bool selected[100]{};

void mst_prim(int N, Vertex V[], int weight[][100], bool selected[], int r) {
  priority_queue<Vertex, vector<Vertex>, greater<vector<Vertex>::value_type>> q;
  V[r].distance = 0;
  q.push(V[r]);
  while (!q.empty()) {
    Vertex u = q.top();
    q.pop();
    selected[u.n] = true;
    for (int i = 0; i < u.adj.size(); ++i) {
      Vertex *v = u.adj[i];
      if (!selected[v->n] && weight[u.n][v->n] < v->distance) {
        int less = min(u.n, v->n);
        int greater = max(u.n, v->n);
        v->distance = weight[less][greater];
        v->pth = u.n;
        q.push(*v);
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
  V[5] = Vertex(5);
  V[6] = Vertex(6);
  V[7] = Vertex(7);
  V[8] = Vertex(8);

  V[0].adj = vector<Vertex *>{&V[1], &V[7]};
  V[1].adj = vector<Vertex *>{&V[0], &V[2], &V[7]};
  V[2].adj = vector<Vertex *>{&V[1], &V[3], &V[5], &V[8]};
  V[3].adj = vector<Vertex *>{&V[2], &V[4], &V[5]};
  V[4].adj = vector<Vertex *>{&V[3], &V[5]};
  V[5].adj = vector<Vertex *>{&V[2], &V[3], &V[4], &V[6]};
  V[6].adj = vector<Vertex *>{&V[5], &V[7], &V[8]};
  V[7].adj = vector<Vertex *>{&V[0], &V[1], &V[6], &V[8]};
  V[8].adj = vector<Vertex *>{&V[2], &V[6], &V[7]};

  weight[0][1] = 4;
  weight[0][7] = 8;
  weight[1][2] = 8;
  weight[1][7] = 11;
  weight[2][3] = 7;
  weight[2][5] = 4;
  weight[2][8] = 2;
  weight[3][4] = 9;
  weight[3][5] = 14;
  weight[4][5] = 10;
  weight[5][6] = 2;
  weight[6][7] = 1;
  weight[6][8] = 6;
  weight[7][8] = 7;

  mst_prim(N, V, weight, selected, 0);
  int total_weight = 0;
  printf("edges: ");
  for (int i = 1; i < N; ++i) {
    total_weight += V[i].distance;
    printf("(%d, %d), ", V[i].pth, V[i].n);
  }
  printf("\n");
  printf("total weight: %d\n", total_weight);
}

// edges: (0, 1), (1, 2), (2, 3), (3, 4), (2, 5), (5, 6), (6, 7), (2, 8),
// total weight: 37
