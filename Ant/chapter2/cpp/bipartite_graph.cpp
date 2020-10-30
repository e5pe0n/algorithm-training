#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_N 1000

using namespace std;

int N, K;
vector<int> G[MAX_N];
int color[MAX_N]{};

bool dfs(int u, int c) {
  color[u] = c;
  for (auto v : G[u]) {
    if (color[v] == c) {
      return false;
    }
    if (color[v] == 0 && !dfs(v, -c)) {
      return false;
    }
  }
  return true;
}

int main() {
  ifstream ifs("../testset/bipartite_graph/test3.txt");
  ifs >> N >> K;
  for (int i = 0; i < K; ++i) {
    int u, v;
    ifs >> u >> v;
    --u;
    --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (dfs(0, 1)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}