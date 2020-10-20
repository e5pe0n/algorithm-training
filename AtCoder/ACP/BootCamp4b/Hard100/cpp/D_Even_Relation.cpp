#include <deque>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000

using namespace std;

struct Edge {
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int N;
vector<Edge> E[MAX_N];
bool used[MAX_N]{};
bool C[MAX_N]{};

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    E[u - 1].emplace_back(u - 1, v - 1, w);
    E[v - 1].emplace_back(v - 1, u - 1, w);
  }
  deque<int> q{0};
  while (!q.empty()) {
    int p = q.front();
    q.pop_front();
    if (used[p]) {
      continue;
    }
    used[p] = true;
    for (auto e : E[p]) {
      if (!used[e.v]) {
        if (e.w % 2 != 0) {
          C[e.v] = !C[e.u];
        } else {
          C[e.v] = C[e.u];
        }
        q.push_back(e.v);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%d\n", C[i]);
  }
}