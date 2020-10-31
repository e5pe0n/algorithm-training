#include <fstream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_N 10'000
#define MAX_K 10'000

using namespace std;

typedef pair<int, int> P;

struct Edge {
  int u, v, weight;
  Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

int N, K, ans;
vector<Edge> G[MAX_N];
bool used[MAX_N]{};

int prim() {
  int res = 0;
  used[0] = true;
  priority_queue<P, vector<P>, greater<P>> q;
  for (auto e : G[0]) {
    q.push(P(e.weight, e.v));
  }
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int u = p.second;
    if (used[u]) {
      continue;
    }
    used[u] = true;
    res += p.first;
    for (auto e : G[u]) {
      if (!used[e.v]) {
        q.push(P(e.weight, e.v));
      }
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/minimum_spanning_tree/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < K; ++i) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    --u;
    --v;
    G[u].emplace_back(u, v, weight);
    G[v].emplace_back(v, u, weight);
  }
  ans = prim();
  printf("%d\n", ans);
}