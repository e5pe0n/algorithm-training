#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_H 500

using namespace std;

char C[MAX_H][MAX_H]{};
char B[MAX_H][MAX_H]{};

bool f(int i, int j, int H, int W) { return 0 <= i && i < H && 0 <= j && j < W && !B[i][j]; }

vector<pair<int, int>> g(int i, int j) {
  return vector<pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
}

bool dfs(int i, int j, int H, int W) {
  B[i][j] = true;
  vector<pair<int, int>> v = g(i, j);
  for (int k = 0; k < 4; ++k) {
    int _i = v[k].first;
    int _j = v[k].second;
    if (f(_i, _j, H, W)) {
      if (C[_i][_j] == 'g') {
        return true;
      } else if (C[_i][_j] == '.') {
        if (dfs(v[k].first, v[k].second, H, W)) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int H, W;
  cin >> H >> W;
  int si, sj;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> C[i][j];
      if (C[i][j] == 's') {
        si = i;
        sj = j;
      }
    }
  }
  if (dfs(si, sj, H, W)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}