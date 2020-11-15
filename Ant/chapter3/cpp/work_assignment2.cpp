#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define MAX_N 1000
#define MAX_M 1000
#define MAX_V MAX_N + MAX_M

using namespace std;

int N, M, K;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int u) {
  used[u] = true;
  for (auto v : G[u]) {
    int _u = match[v];
    if (_u < 0 || !used[_u] && dfs(_u)) {
      // u is computers, _u is computer which is already assigned to work v, v is work
      // increase num of matching only when w < 0 i.e. _u find a new work.
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  ifstream ifs("../testset/work_assignment/test2.txt");
  ifs >> N >> M >> K;
  for (int i = 0; i < K; ++i) {
    int u, v;
    ifs >> u >> v;
    add_edge(u - 1, v - 1);
  }

  int res = 0;
  memset(match, -1, sizeof(match));
  for (int u = 0; u < N; ++u) {
    if (match[u] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(u)) {
        ++res;
      }
    }
  }
  printf("%d\n", res);
}