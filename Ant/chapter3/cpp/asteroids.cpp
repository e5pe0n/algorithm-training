#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_N 500
#define MAX_V MAX_N * 2
using namespace std;

int N, K;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

bool dfs(int u) {
  used[u] = true;
  for (auto v : G[u]) {
    int _u = match[v];
    if (_u < 0 || (!used[_u] && dfs(_u))) {
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  fill(match, match + N * 2, -1);
  for (int u = 0; u < N; ++u) {
    if (match[u] < 0) {
      fill(used, used + N * 2, 0);
      if (dfs(u)) {
        ++res;
      }
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/asteroids/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < K; ++i) {
    int x, y;
    ifs >> x >> y;
    --x;
    --y;
    G[x].push_back(N + y);
    G[N + y].push_back(x);
  }
  int res = bipartite_matching();
  printf("%d\n", res);
}