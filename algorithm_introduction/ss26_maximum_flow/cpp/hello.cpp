#include <stdio.h>
#include <vector>

#define N 3

using namespace std;

struct Edge {
  int u;
  Edge() {}
  Edge(int u) : u(u) {}
};

Edge E[N];

void init(Edge E[]) { E[1] = Edge(100); }

int main() {
  init(E);
  printf("%d\n", E[1].u);
}