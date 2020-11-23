#include <bits/stdc++.h>
#define MAX_H 2000
#define MAX_W 2000
#define INF 1'000'000'000
using namespace std;
typedef pair<int, int> pii;

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int H, W;
string A[MAX_H];
pii S, G;
vector<pii> T[26];
bool used[26];
int d[MAX_H][MAX_W];

int bfs() {
  queue<pii> q;
  q.push({S.first, S.second});
  for (int h = 0; h < H; ++h) {
    fill(d[h], d[h] + W, INF);
  }
  d[S.first][S.second] = 0;
  while (!q.empty()) {
    pii p = q.front();
    int i = p.first;
    int j = p.second;
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k];
      int nj = j + dj[k];
      if (0 <= ni && ni < H && 0 <= nj && nj < W && A[ni][nj] != '#' && d[ni][nj] > d[i][j] + 1) {
        d[ni][nj] = d[i][j] + 1;
        q.push({ni, nj});
      }
    }
    if ('a' <= A[i][j] && A[i][j] <= 'z' && !used[A[i][j] - 'a']) {
      for (auto t : T[A[i][j] - 'a']) {
        int ni = t.first;
        int nj = t.second;
        // WA:
        // this condition is not enough
        // because it is possible that (ni, nj) is already queued in for loop above.
        // (d[ni][nj] == d[i][j] in this case so d[ni][nj] = d[i][j] + 1 is wrong.)
        //
        //  if (!(ni == i && nj == j)) {
        //   d[ni][nj] = d[i][j] + 1;
        //   q.push({ni, nj});
        // }
        if (d[ni][nj] > d[i][j] + 1) {
          d[ni][nj] = d[i][j] + 1;
          q.push({ni, nj});
        }
      }
      used[A[i][j] - 'a'] = true;
    }
  }
  int res = d[G.first][G.second];
  if (res == INF) {
    res = -1;
  }
  return res;
}

void solve() {
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == 'S') {
        S = {i, j};
      }
      if (A[i][j] == 'G') {
        G = {i, j};
      }
      if ('a' <= A[i][j] && A[i][j] <= 'z') {
        T[A[i][j] - 'a'].push_back({i, j});
      }
    }
  }
  printf("%d\n", bfs());
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
  }
  solve();
}