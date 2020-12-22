#include <bits/stdc++.h>
#define MAX_H 100
#define MAX_W 100
#define INF 1'000'000'000
using namespace std;
typedef pair<int, int> pii;

int H, W;
string S[MAX_H];
int C[MAX_H][MAX_W];

void bfs() {
  queue<pii> q;
  fill((int *)C, (int *)C + sizeof(C) / sizeof(int), INF);
  C[0][0] = S[0][0] == '#';
  q.push({0, 0});
  while (!q.empty()) {
    int i, j;
    tie(i, j) = q.front();
    q.pop();
    if (i + 1 < H && C[i + 1][j] > C[i][j] + (S[i][j] == '.' && S[i + 1][j] == '#')) {
      C[i + 1][j] = C[i][j] + (S[i][j] == '.' && S[i + 1][j] == '#');
      q.push({i + 1, j});
    }
    if (j + 1 < W && C[i][j + 1] > C[i][j] + (S[i][j] == '.' && S[i][j + 1] == '#')) {
      C[i][j + 1] = C[i][j] + (S[i][j] == '.' && S[i][j + 1] == '#');
      q.push({i, j + 1});
    }
  }
}

void solve() {
  bfs();
  printf("%d\n", C[H - 1][W - 1]);
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}