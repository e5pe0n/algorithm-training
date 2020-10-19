#include <deque>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_H 1000
#define MAX_W 1000

using namespace std;

int H, W;
string A[MAX_H]{};

bool valid(int i, int j) { return 0 <= i && i < H && 0 <= j && j < W && A[i][j] == '.'; }

int main() {
  cin >> H >> W;
  deque<vector<int>> q;
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == '#') {
        q.push_back(vector<int>{i, j, 0});
      }
    }
  }
  int ans = 0;
  while (!q.empty()) {
    vector<int> p = q.front();
    q.pop_front();
    int i = p[0];
    int j = p[1];
    int cc = p[2];
    if (cc > 0 && A[i][j] == '#') {
      continue;
    }
    A[i][j] = '#';
    ans = cc;
    if (valid(i - 1, j)) {
      q.push_back(vector<int>{i - 1, j, cc + 1});
    }
    if (valid(i + 1, j)) {
      q.push_back(vector<int>{i + 1, j, cc + 1});
    }
    if (valid(i, j - 1)) {
      q.push_back(vector<int>{i, j - 1, cc + 1});
    }
    if (valid(i, j + 1)) {
      q.push_back(vector<int>{i, j + 1, cc + 1});
    }
  }
  printf("%d\n", ans);
}