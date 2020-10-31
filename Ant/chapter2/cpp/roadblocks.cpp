#include <fstream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_N 5000
#define MAX_R 100'000
#define INF 1'000'000'000

using namespace std;

typedef pair<int, int> P;

struct Edge {
  int u, v, weight;
  Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

int N, R;
int dist1[MAX_N], dist2[MAX_N];
vector<Edge> G[MAX_N];

int main() {
  ifstream ifs("../testset/roadblocks/test1.txt");
  ifs >> N >> R;
  fill(dist1, dist1 + N, INF);
  fill(dist2, dist2 + N, INF);
  for (int i = 0; i < R; ++i) {
    int u, v, weight;
    ifs >> u >> v >> weight;
    --u;
    --v;
    G[u].emplace_back(u, v, weight);
    G[v].emplace_back(v, u, weight);
  }
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(P(0, 0));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int u = p.second;
    int _d = p.first;
    if (dist2[u] < _d) {
      continue;
    }
    for (auto e : G[u]) {
      int d = _d + e.weight;
      if (dist1[e.v] > d) {
        swap(dist1[e.v], d);
        q.push(P(dist1[e.v], e.v));
      }
      if (dist2[e.v] > d && dist1[e.v] < d) {
        swap(dist2[e.v], d);
        q.push(P(dist2[e.v], e.v));
      }
    }
  }
  printf("%d\n", dist2[N - 1]);
}