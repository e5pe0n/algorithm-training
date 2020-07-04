#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_M 28

using namespace std;

int C[MAX_M];
bool D[MAX_M][MAX_M];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    D[a - 1][b - 1] = true;
    D[b - 1][a - 1] = true;
  }

  for (int i = 0; i < N; ++i) {
    C[i] = i;
  }

  int cnt = 0;
  do {
    bool flg = true;
    for (int i = 0; i < N - 1; ++i) {
      if (!D[C[i]][C[i + 1]]) {
        flg = false;
        break;
      }
    }
    cnt += flg;
  } while (next_permutation(C + 1, C + N));
  printf("%d\n", cnt);
}