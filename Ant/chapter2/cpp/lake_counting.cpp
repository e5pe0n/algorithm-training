#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 100
#define MAX_M 100

using namespace std;

int N, M;
string A[MAX_N]{};

void dfs(int _i, int _j) {
  A[_i][_j] = '.';
  for (int di = -1; di <= 1; ++di) {
    for (int dj = -1; dj <= 1; ++dj) {
      int i = _i + di;
      int j = _j + dj;
      if (0 <= i && i < N && 0 <= j && j < M && A[i][j] == 'W') {
        dfs(i, j);
      }
    }
  }
}

int main() {
  ifstream ifs("../testset/lake_counting/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (A[i][j] == 'W') {
        dfs(i, j);
        ++res;
      }
    }
  }
  printf("%d\n", res);
}