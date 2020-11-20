#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define MAX_N 100
#define MAX_F 100
#define MAX_D 100
#define INF 1'000'000'000

using namespace std;

struct Edge {
  int v, cap, rev;
};

int N, F, D;
vector<int> likeF[MAX_N];
vector<int> likeD[MAX_N];
bool used[MAX_N * 2 + MAX_F + MAX_D + 2];

vector<Edge> G[MAX_N * 2 + MAX_F + MAX_D + 2];

void add_edge(int u, int v, int cap) {
  G[u].push_back(Edge{v, cap, G[v].size()});
  G[v].push_back(Edge{u, 0, G[u].size() - 1});
}

int dfs(int u, int t, int f) {
  if (u == t) {
    return f;
  }
  used[u] = true;
  for (auto &e : G[u]) {
    if (e.cap > 0 && !used[e.v]) {
      int d = dfs(e.v, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.v][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int res = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if (f == 0) {
      return res;
    }
    res += f;
  }
}

void solve() {
  int s = N * 2 + F + D;
  int t = s + 1;
  for (int i = 0; i < F; ++i) {
    add_edge(s, N * 2 + i, 1);
  }
  for (int i = 0; i < D; ++i) {
    add_edge(N * 2 + F + i, t, 1);
  }
  for (int i = 0; i < N; ++i) {
    add_edge(i, N + i, 1);
    for (auto f : likeF[i]) {
      add_edge(N * 2 + f, i, 1);
    }
    for (auto d : likeD[i]) {
      add_edge(N + i, N * 2 + F + d, 1);
    }
  }
  printf("%d\n", max_flow(s, t));
}

int main() {
  ifstream ifs("../testset/dining/test1.txt");
  ifs >> N >> F >> D;
  for (int i = 0; i < N; ++i) {
    int n;
    ifs >> n;
    likeF[i] = vector<int>(n);
    for (int j = 0; j < n; ++j) {
      ifs >> likeF[i][j];
      --likeF[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    int n;
    ifs >> n;
    likeD[i] = vector<int>(n);
    for (int j = 0; j < n; ++j) {
      ifs >> likeD[i][j];
      --likeD[i][j];
    }
  }
  solve();
}