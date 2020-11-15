#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

struct Edge {
  int u, v, cap;
};

vector<Edge> G[1];

int main() {
  G[0].push_back(Edge{1, 2, 3});
  for (auto e : G[0]) {
    e.cap -= 100;
  }
  printf("%d\n", G[0][0].cap);
}