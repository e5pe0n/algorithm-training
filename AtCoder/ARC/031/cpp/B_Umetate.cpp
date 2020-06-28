#include <deque>
#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>

#define N 10

using namespace std;

char C[N][N];

int bfs(int i, int j, bool D[][N]) {
  int cnt = 0;
  deque<pair<int, int>> dq{{i, j}};
  while (!dq.empty()) {
    pair<int, int> p = dq.front();
    dq.pop_front();
    int _i = p.first;
    int _j = p.second;
    if (_i - 1 >= 0 && C[_i - 1][_j] == 'o' && !D[_i - 1][_j]) {
      dq.push_back({_i - 1, _j});
      D[_i - 1][_j] = true;
      ++cnt;
    }
    if (_i + 1 < N && C[_i + 1][_j] == 'o' && !D[_i + 1][_j]) {
      dq.push_back({_i + 1, _j});
      D[_i + 1][_j] = true;
      ++cnt;
    }
    if (_j - 1 >= 0 && C[_i][_j - 1] == 'o' && !D[_i][_j - 1]) {
      dq.push_back({_i, _j - 1});
      D[_i][_j - 1] = true;
      ++cnt;
    }
    if (_j + 1 < N && C[_i][_j + 1] == 'o' && !D[_i][_j + 1]) {
      dq.push_back({_i, _j + 1});
      D[_i][_j + 1] = true;
      ++cnt;
    }
  }
  return cnt;
}

int main() {
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < N; ++j) {
      C[i][j] = s[j];
      if (s[j] == 'o') {
        ++cnt;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (C[i][j] == 'x') {
        bool D[N][N]{};
        int _cnt = bfs(i, j, D);
        if (cnt == _cnt) {
          printf("YES\n");
          return 0;
        }
      }
    }
  }
  printf("NO\n");
}