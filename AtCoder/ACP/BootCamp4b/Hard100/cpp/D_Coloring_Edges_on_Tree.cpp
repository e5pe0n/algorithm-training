#include <algorithm>
#include <deque>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000

using namespace std;

struct Edge {
  int idx, u, v;
  Edge(int idx, int u, int v) : idx(idx), u(u), v(v) {}
};

int N;
vector<Edge> E[MAX_N]{};
bool used[MAX_N]{};
int C[MAX_N - 1]{};

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    E[a].emplace_back(i, a, b);
    E[b].emplace_back(i, b, a);
  }
  int K = 0;
  for (int i = 0; i < N; ++i) {
    K = max(K, (int)E[i].size());
  }
  deque<vector<int>> q{vector<int>{0, -1, -1}};
  while (!q.empty()) {
    auto p = q.front();
    int u = p[0];
    int idx = p[1];
    int c = p[2];
    q.pop_front();
    if (used[u]) {
      continue;
    }
    used[u] = true;
    if (idx >= 0 && c >= 0) {
      C[idx] = c;
    }
    int i = 1;
    for (auto e : E[u]) {
      if (!used[e.v]) {
        q.push_back(vector<int>{e.v, e.idx, (c + i++) % K});
      }
    }
  }
  printf("%d\n", K);
  for (int i = 0; i < N - 1; ++i) {
    printf("%d\n", C[i] + 1);
  }
}