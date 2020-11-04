#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_M 15
#define MAX_N 15

using namespace std;

const int di[5] = {-1, 0, 1, 0, 0};
const int dj[5] = {0, -1, 0, 1, 0};

int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N];
int work[MAX_M][MAX_N];

int get(int _i, int _j) {
  int c = tile[_i][_j];
  for (int k = 0; k < 5; ++k) {
    int i = _i + di[k];
    int j = _j + dj[k];
    if (0 <= i && i < M && 0 <= j && j < N) {
      c += work[i][j];
    }
  }
  return c % 2;
}

int calc() {
  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (get(i - 1, j) != 0) {
        work[i][j] = 1;
      }
    }
  }
  for (int j = 0; j < N; ++j) {
    if (get(N - 1, j) != 0) {
      return -1;
    }
  }
  int res = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      res += work[i][j];
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/fliptile/test1.txt");
  ifs >> M >> N;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      ifs >> tile[i][j];
    }
  }
  int ans = -1;
  for (int i = 0; i < 1 << N; ++i) {
    memset(work, 0, sizeof(work));
    for (int j = 0; j < N; ++j) {
      work[0][N - j - 1] = i >> j & 1;
    }
    int res = calc();
    if (res >= 0 && (ans < 0 || ans > res)) {
      ans = res;
      memcpy(opt, work, sizeof(work));
    }
  }
  if (ans < 0) {
    printf("IMPOSSIBLE\n");
  } else {
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        printf("%d%c", opt[i][j], j == N - 1 ? '\n' : ' ');
      }
    }
  }
}