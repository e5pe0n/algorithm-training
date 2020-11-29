#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_M 80
#define MAX_N 80
#define MAX_V MAX_M *MAX_N

using namespace std;

const int dx[] = {-1, -1, 1, 1};
const int dy[] = {-1, 1, -1, 1};

int M, N, V;
string seat[MAX_M];
vector<int> G[MAX_V];
bool used[MAX_V];
int match[MAX_V];

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

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
  memset(match, -1, sizeof(match));
  for (int x = 0; x < N; x += 2) {
    for (int y = 0; y < M; ++y) {
      int u = x * M + y;
      if (match[u] < 0) {
        memset(used, false, sizeof(used));
        if (dfs(u)) {
          ++res;
        }
      }
    }
  }
  return res;
}

void solve() {
  int num = 0;
  V = M * N;
  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
      if (seat[y][x] == '.') {
        ++num;
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (0 <= x2 && x2 < N && 0 <= y2 && y2 < M && seat[y2][x2] == '.') {
            add_edge(x * M + y, x2 * M + y2);
          }
        }
      }
    }
  }
  printf("%d\n", num - bipartite_matching());
}

int main() {
  ifstream ifs("../testset/no_cheating/test1.txt");
  ifs >> M >> N;
  for (int i = 0; i < M; ++i) {
    ifs >> seat[i];
  }
  solve();
}