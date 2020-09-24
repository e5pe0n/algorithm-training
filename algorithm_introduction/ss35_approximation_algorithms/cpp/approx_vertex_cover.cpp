#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct Edge {
  int u;
  int v;
};

vector<int> approx_vertex_cover(vector<Edge> E) {
  vector<int> C;
  while (E.size() > 0) {
    Edge e = E.back();
    E.pop_back();
    C.push_back(e.u);
    C.push_back(e.v);
    vector<Edge> _E = E;
    E.clear();
    for (auto _e : _E) {
      if (_e.u != e.u && _e.u != e.v && _e.v != e.u && _e.v != e.v) {
        E.push_back(_e);
      }
    }
  }
  return C;
}

int main() {
  vector<Edge> E{Edge{0, 1}, Edge{1, 2}, Edge{2, 3}, Edge{2, 4},
                 Edge{3, 4}, Edge{3, 5}, Edge{4, 5}, Edge{3, 6}};

  vector<int> C = approx_vertex_cover(E);
  for (auto v : C) {
    printf("%d ", v);
  }
  printf("\n");
}
