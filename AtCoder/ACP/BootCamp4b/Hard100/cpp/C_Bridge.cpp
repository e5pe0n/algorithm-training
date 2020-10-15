#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 50

using namespace std;

struct Edge {
  int u, v;
  Edge(int u, int v) : u(u), v(v) {}
};

int par[MAX_N]{};
int rnk[MAX_N]{};

void init(int N) {
  for (int i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  }
  par[x] = find(par[x]);
  return par[x];
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (rnk[y] > rnk[x]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) {
      ++rnk[x];
    }
  }
}

bool same(int x, int y) { return find(x) == find(y); }

int main() {
  int N, M;
  cin >> N >> M;
  vector<Edge> E{};
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    E.emplace_back(a - 1, b - 1);
  }
  int ans = M;
  for (int i = 0; i < M; ++i) {
    init(N);
    for (int j = 0; j < M; ++j) {
      if (i != j && !same(E[j].u, E[j].v)) {
        unite(E[j].u, E[j].v);
      }
    }
    for (int j = 0; j < N; ++j) {
      find(j);
    }
    bool is_tree = true;
    for (int j = 1; j < N; ++j) {
      if (par[j] != par[0]) {
        is_tree = false;
        break;
      }
    }
    if (is_tree) {
      --ans;
    }
  }
  printf("%d\n", ans);
}