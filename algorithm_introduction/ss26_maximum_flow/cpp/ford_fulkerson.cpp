#include <list>
#include <memory>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

#define N 6

using namespace std;

struct Edge {
  int u;
  int v;
  int f;
  int c;
  int cf = c - f;
  string to_str() { return "(u: " + to_string(u) + ", v: " + to_string(v) + ", f: " + to_string(f) + ")"; }
};

vector<Edge> E[N]{};
vector<Edge *> _E[N]{};
set<pair<int, int>> E_s;
Edge E_a[][N];

vector<Edge *> bfs(vector<Edge *> _E[], int s, int t) {
  bool selected[N]{};
  selected[0] = true;

  list<int> q;
  vector<Edge *> p;
  q.push_back(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    if (u == t) {
      break;
    }
    for (auto e : _E[u]) {
      if (selected[e->v] < 0 && e->cf > 0) {
        selected[e->v] = e->u;
        q.push_back(e->v);
        p.push_back(e);
        break;
      }
    }
  }

  if (selected[N - 1] < 0) {
    // Augmenting path is not found
    return vector<Edge *>{};
  } else {
    p;
  }

  return p;
}

void ford_fulkerson(vector<Edge> E[], int s, int t) {
  vector<Edge> Ef[N];
  for (int i = 0; i < N; ++i) {
    for (auto e : E[i]) {
      Ef[e.v].emplace_back(e.v, e.u, e.c, e.f);
    }
  }
  for (int i = 0; i < N; ++i) {
    for (auto e : E[i]) {
      _E[i].push_back(&e);
      E_s.emplace(make_pair(e.u, e.v));
    }
    for (auto e : Ef[i]) {
      _E[i].push_back(&e);
    }
  }
  while (true) {
    vector<Edge *> p = bfs(_E, s, t);
    if (p.empty()) {
      break;
    }
    int cf = p[0]->cf;
    for (auto e : p) {
      cf = min(cf, e->cf);
    }
    for (auto e : p) {
      if (E_s.find(make_pair(e->u, e->v)) != E_s.end()) {
        e->f += cf;
      } else {
        for (auto ef : _E[e->v]) {
          if (ef->u == e->v) {
            ef->f -= cf;
            break;
          }
        }
      }
    }
  };
}

int main() {
  E[0] = vector<Edge>{Edge{0, 1, 0, 16}, Edge{0, 2, 0, 13}};
  E[1] = vector<Edge>{Edge{1, 3, 0, 12}};
  E[2] = vector<Edge>{Edge{2, 1, 0, 4}, Edge{2, 4, 0, 14}};
  E[3] = vector<Edge>{Edge{3, 5, 0, 20}};
  E[4] = vector<Edge>{Edge{4, 3, 0, 7}, Edge{4, 5, 0, 4}};

  ford_fulkerson(E, 0, 5);

  for (int i = 0; i < N; ++i) {
    for (auto e : E[i]) {
      printf("%s\n", e.to_str().c_str());
    }
  }
}