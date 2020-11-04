#include <fstream>
#include <memory.h>
#include <stdio.h>

#define MAX_N 5000

using namespace std;

int N, M, K;
int dir[MAX_N]; // 0 := F, 1 := B
int f[MAX_N];

int calc(int k) {
  memset(f, 0, sizeof(f));
  int res = 0;
  int s = 0;
  for (int i = 0; i + k <= N; ++i) {
    if ((dir[i] + s) % 2 != 0) {
      ++res;
      f[i] = 1;
    }
    s += f[i];
    if (i - k + 1 >= 0) {
      s -= f[i - k + 1];
    }
  }
  for (int i = N - k + 1; i < N; ++i) {
    if ((dir[i] + s) % 2 != 0) {
      return -1;
    }
    if (i - k + 1 >= 0) {
      s -= f[i - k + 1];
    }
  }
  return res;
}

int main() {
  ifstream ifs("../testset/face_the_right_way/test1.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    char d;
    ifs >> d;
    dir[i] = d == 'B';
  }
  K = 1;
  M = N;
  for (int k = 1; k <= N; ++k) {
    int m = calc(k);
    if (0 <= m && m < M) {
      M = m;
      K = k;
    }
  }
  printf("%d %d\n", M, K);
}