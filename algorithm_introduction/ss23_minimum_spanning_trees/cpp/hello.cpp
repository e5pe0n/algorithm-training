#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

struct Vertex {
  int n;
  int distance;
  friend bool operator<(const Vertex &left, const Vertex &right) { return left.distance < right.distance; }
  friend bool operator>(const Vertex &left, const Vertex &right) { return left.distance > right.distance; }
};

int main() {
  Vertex v0{0, 100};
  Vertex v1{1, 100};
  Vertex v2{2, 5};

  priority_queue<Vertex *, vector<Vertex *>, greater<vector<Vertex *>::value_type>> q;
  q.push(&v0);
  q.push(&v1);
  q.push(&v2);

  Vertex *v = q.top();
  printf("%d\n", v->n);
}