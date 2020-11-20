// WA but I don't know the reason
#include <iostream>
#include <memory.h>
#include <queue>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

#define MAX_H 1000
#define MAX_W 1000
#define INF 1'000'000'000

using namespace std;
typedef pair<int, int> pii;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int H, W;
int Ch, Cw, Dh, Dw;
string S[MAX_H];
int D[MAX_H][MAX_W];
bool B[MAX_H][MAX_W];

void bfs(int sh, int sw, int n) {
  queue<pii> q;
  q.push(pii(sh, sw));
  D[sh][sw] = n;
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    int i = p.first;
    int j = p.second;
    for (int k = 0; k < 4; ++k) {
      int _i = i + dx[k];
      int _j = j + dy[k];
      if (0 <= _i && _i < H && 0 <= _j && _j < W && S[_i][_j] == '.' && D[_i][_j] < 0) {
        D[_i][_j] = n;
        q.push(pii(_i, _j));
      }
    }
  }
}

int bfs2(int sh, int sw, int k, int n) {
  vector<int> d(n, INF);
  d[k] = 0;
  queue<pii> q;
  q.push(pii(sh, sw));
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    int i = p.first;
    int j = p.second;
    if (D[i][j] == D[Dh][Dw]) {
      continue;
    }
    for (int di = -2; di <= 2; ++di) {
      for (int dj = -2; dj <= 2; ++dj) {
        int _i = i + di;
        int _j = j + dj;
        if (0 <= _i && _i < H && 0 <= _j && _j < W && S[_i][_j] == '.') {
          if (D[_i][_j] == D[i][j] && d[D[_i][_j]] > d[D[i][j]]) {
            d[D[_i][_j]] = d[D[i][j]];
            B[_i][_j] = true;
            q.push(pii(_i, _j));
          } else if (D[_i][_j] != D[i][j] && d[D[_i][_j]] > d[D[i][j]] + 1) {
            d[D[_i][_j]] = d[D[i][j]] + 1;
            B[_i][_j] = true;
            q.push(pii(_i, _j));
          } else if (!B[_i][_j]) {
            B[_i][_j] = true;
            q.push(pii(_i, _j));
          }
        }
      }
    }
  }
  int res = d[D[Dh][Dw]];
  if (res == INF) {
    res = -1;
  }
  return res;
}

void solve() {
  memset(D, -1, sizeof(D));
  int n = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.' && D[i][j] < 0) {
        bfs(i, j, n++);
      }
    }
  }
  int res = bfs2(Ch, Cw, D[Ch][Cw], n);
  printf("%d\n", res);
}

int main() {
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
  --Ch;
  --Cw;
  --Dh;
  --Dw;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}