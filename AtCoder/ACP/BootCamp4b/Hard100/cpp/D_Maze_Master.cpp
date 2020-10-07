#include <algorithm>
#include <deque>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_H 20
#define MAX_W 20
#define MAX_HW 400

using namespace std;

string S[MAX_H]{};
bool B[MAX_H][MAX_W]{};

bool valid(int i, int j, int H, int W) {
  return 0 <= i && i < H && 0 <= j && j < W && S[i][j] == '.' && !B[i][j];
}

int bfs(int i, int j, int H, int W) {
  for (int a = 0; a < H; ++a) {
    for (int b = 0; b < W; ++b) {
      B[a][b] = false;
    }
  }
  deque<vector<int>> q{vector<int>{i, j, -1}};
  int dist = 0;
  while (!q.empty()) {
    vector<int> p = q.front();
    q.pop_front();
    i = p[0];
    j = p[1];
    if (B[i][j]) {
      continue;
    }
    int d = p[2] + 1;
    dist = max(dist, d);
    B[i][j] = true;
    if (valid(i - 1, j, H, W)) {
      q.push_back(vector<int>{i - 1, j, d});
    }
    if (valid(i + 1, j, H, W)) {
      q.push_back(vector<int>{i + 1, j, d});
    }
    if (valid(i, j - 1, H, W)) {
      q.push_back(vector<int>{i, j - 1, d});
    }
    if (valid(i, j + 1, H, W)) {
      q.push_back(vector<int>{i, j + 1, d});
    }
  }
  return dist;
}

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.') {
        ans = max(ans, bfs(i, j, H, W));
      }
    }
  }
  printf("%d\n", ans);
}
