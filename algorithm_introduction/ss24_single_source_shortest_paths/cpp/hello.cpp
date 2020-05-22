#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

struct Vertex {
  int n;
  int dist;
  friend bool operator<(const Vertex &lhs, const Vertex &rhs) { return lhs.dist < rhs.dist; }
  friend bool operator>(const Vertex &lhs, const Vertex &rhs) { return lhs.dist > rhs.dist; }
};

int main() {
  vector<Vertex> V{Vertex{0, 10}, Vertex{1, 5}, Vertex{2, 7}};

  // priority_queue<Vertex *, vector<Vertex *>, greater<vector<Vertex *>::value_type>> q;
  // q.push(&V[0]);
  // q.push(&V[1]);
  // q.push(&V[2]);

  // Vertex *v = q.top();
  // printf("v->n: %d\n", v->n);

  // v->dist = 0;
  // q.push(v);

  // v = q.top();
  // printf("v->n: %d\n", v->n);

  priority_queue<Vertex, vector<Vertex>, greater<vector<Vertex>::value_type>> q;
  q.push(V[0]);
  q.push(V[1]);
  q.push(V[2]);

  Vertex v = q.top();
  printf("%d\n", v.n);
}
