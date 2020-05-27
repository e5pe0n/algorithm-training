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
Edge *E_m[][N];

void dfs_visit(vector<Edge *> _E[], int u, int t, int pth[]) {
  if (pth[t] >= 0 || u == t) {
    return;
  }
  for (auto e : _E[u]) {
    if (pth[e->v] < 0 && e->cf > 0) {
      pth[e->v] = u;
      dfs_visit(_E, e->v, t, pth);
    }
  }
}

vector<Edge *> dfs(vector<Edge *> _E[], int s, int t) {
  int pth[N];
  memset(pth, -1, N);

  dfs_visit(_E, s, t, pth);

  if (pth[t] < 0) {
    // Augmenting path is not found
    return vector<Edge *>{};
  } else {
    vector<Edge *> p;
    int cur = t;
    while (cur != s) {
      int pre = pth[cur];
      p.push_back(_E[pre][cur]);
      cur = pre;
    }
    return p;
  }
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
      E_m[i][e.v] = &e;
    }
    for (auto e : Ef[i]) {
      _E[i].push_back(&e);
    }
  }
  while (true) {
    vector<Edge *> p = dfs(_E, s, t);
    if (p.empty()) {
      break;
    }
    int cf = p[0]->cf;
    for (auto e : p) {
      cf = min(cf, e->cf);
    }
    for (auto e : p) {
      if (E_m[e->u][e->v] != nullptr) {
        e->f += cf;
      } else {
        e->f -= cf;
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