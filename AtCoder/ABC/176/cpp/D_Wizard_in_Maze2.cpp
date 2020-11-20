#include <iostream>
#include <memory.h>
#include <queue>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

#define MAX_H 1000
#define MAX_W 1000

using namespace std;
typedef pair<int, int> pii;

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int H, W, Ch, Cw, Dh, Dw;
string S[MAX_H];
int d[MAX_H][MAX_W];

vector<pii> bfs(vector<pii> V, int cost) {
  vector<pii> _V;
  for (auto v : V) {
    if (d[v.first][v.second] >= 0) {
      continue;
    }
    queue<pii> q;
    q.push(pii(v.first, v.second));
    _V.push_back(pii(v.first, v.second));
    d[v.first][v.second] = cost;
    while (!q.empty()) {
      pii p = q.front();
      q.pop();
      int i = p.first;
      int j = p.second;
      for (int k = 0; k < 4; ++k) {
        int _i = i + di[k];
        int _j = j + dj[k];
        if (0 <= _i && _i < H && 0 <= _j && _j < W && S[_i][_j] == '.' && d[_i][_j] < 0) {
          d[_i][_j] = cost;
          q.push(pii(_i, _j));
          _V.push_back(pii(_i, _j));
        }
      }
    }
  }
  return _V;
}

void solve() {
  memset(d, -1, sizeof(d));
  vector<pii> V{pii(Ch, Cw)};
  int cost = 0;
  while (V.size() > 0) {
    vector<pii> _V = bfs(V, cost++);
    V.clear();
    for (auto _v : _V) {
      for (int _di = -2; _di <= 2; ++_di) {
        for (int _dj = -2; _dj <= 2; ++_dj) {
          int i = _v.first + _di;
          int j = _v.second + _dj;
          if (0 <= i && i < H && 0 <= j && j < W && S[i][j] == '.' && d[i][j] < 0) {
            V.push_back(pii(i, j));
          }
        }
      }
    }
  }
  printf("%d\n", d[Dh][Dw]);
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