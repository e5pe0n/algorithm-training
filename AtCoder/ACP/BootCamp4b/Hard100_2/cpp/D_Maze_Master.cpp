#include <bits/stdc++.h>
#define MAX_H 20
#define MAX_W 20
using namespace std;
typedef long long ll;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

ll H, W;
string S[MAX_H];
bool used[MAX_H][MAX_W];

int bfs(int sx, int sy) {
  for (int i = 0; i < H; ++i) {
    fill(used[i], used[i] + W, false);
  }
  queue<vector<int>> q;
  q.push({sx, sy, 0});
  int res = 0;
  used[sx][sy] = true;
  while (!q.empty()) {
    vector<int> v = q.front();
    int x = v[0];
    int y = v[1];
    int d = v[2];
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] != '#' && !used[nx][ny]) {
        used[nx][ny] = true;
        q.push({nx, ny, d + 1});
        res = max(res, d + 1);
      }
    }
  }
  return res;
}

void solve() {
  int res = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] != '#') { res = max(res, bfs(i, j)); }
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}