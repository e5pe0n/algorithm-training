#include <iostream>
#include <stdio.h>

#define MAX_N 100'001
#define MAX_M 100'000

using namespace std;

int B[MAX_N]{};
int C[MAX_N]{};

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    C[i] = 1;
  }
  bool flg = false;
  B[1] = true;
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    if (B[x]) {
      B[y] = true;
    }
    if (x == 1 && !flg && C[1] == 1) {
      B[1] = false;
      flg = true;
    }
    if (y == 1 && !flg) {
      flg = true;
    }
    --C[x];
    ++C[y];
    if (C[x] == 0) {
      B[x] = false;
    }
  }
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    if (B[i] && C[i] > 0) {
      ++res;
    }
  }
  printf("%d\n", res);
}