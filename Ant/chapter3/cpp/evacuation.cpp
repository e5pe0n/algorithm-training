#include <fstream>
#include <memory.h>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_X 12
#define MAX_Y 12
#define MAX_N MAX_X *MAX_Y

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int X, Y;
string field[MAX_X];
vector<int> G[(MAX_N + 1) * (MAX_X + MAX_Y)]; // because of add_edge(.., N * D + j)

vector<int> dX, dY;
vector<int> pX, pY;
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];

int match[MAX_N * (MAX_N + 1)];
bool used[MAX_N * (MAX_N + 1)];

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

void bfs(int x, int y, int d[MAX_X][MAX_Y]) {
  queue<int> qx, qy;
  d[x][y] = 0;
  qx.push(x);
  qy.push(y);
  while (!qx.empty()) {
    x = qx.front();
    qx.pop();
    y = qy.front();
    qy.pop();
    for (int i = 0; i < 4; ++i) {
      int _x = x + dx[i];
      int _y = y + dy[i];
      if (0 <= _x && _x < X && 0 <= _y && _y < Y && field[_x][_y] == '.' && d[_x][_y] < 0) {
        d[_x][_y] = d[x][y] + 1;
        qx.push(_x);
        qy.push(_y);
      }
    }
  }
}

void solve() {
  int N = X * Y;
  dX.clear();
  dY.clear();
  pX.clear();
  pY.clear();
  memset(dist, -1, sizeof(dist));

  // determine the shortest distances from doors
  for (int x = 0; x < X; ++x) {
    for (int y = 0; y < Y; ++y) {
      if (field[x][y] == 'D') {
        dX.push_back(x);
        dY.push_back(y);
        bfs(x, y, dist[x][y]);
      } else if (field[x][y] == '.') {
        pX.push_back(x);
        pY.push_back(y);
      }
    }
  }

  int D = dX.size();
  int P = pX.size();
  for (int i = 0; i < D; ++i) {
    for (int j = 0; j < P; ++j) {
      if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0) {
        for (int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k <= N; ++k) {
          add_edge((k - 1) * D + i, N * D + j);
        }
      }
    }
  }
  if (P == 0) {
    printf("0\n");
    return;
  }
  int cnt = 0;
  memset(match, -1, sizeof(match));
  for (int u = 0; u < N * D; ++u) {
    memset(used, 0, sizeof(used));
    if (dfs(u)) {
      if (++cnt == P) {
        printf("%d\n", u / D + 1);
        return;
      }
    }
  }
  printf("impossible\n");
}

int main() {
  ifstream ifs("../testset/evacuation/test3.txt");
  ifs >> X >> Y;
  for (int i = 0; i < X; ++i) {
    ifs >> field[i];
  }
  solve();
}