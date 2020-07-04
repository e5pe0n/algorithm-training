#include <algorithm>
#include <bitset>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 12
#define MAX_M 66

using namespace std;

bool C[MAX_N][MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    C[x - 1][y - 1] = true;
    C[y - 1][x - 1] = true;
    C[x - 1][x - 1] = true;
    C[y - 1][y - 1] = true;
  }

  if (M == 0) {
    printf("1\n");
    return 0;
  }
  if (M == 1) {
    printf("2\n");
    return 0;
  }

  int res = 0;
  for (int i = 2; i < (1 << N); ++i) {
    bitset<MAX_N> B(i);
    vector<int> V;
    for (int j = 0; j < N; ++j) {
      if (B.test(j)) {
        V.push_back(j);
      }
    }
    bool flg = true;
    for (auto v : V) {
      for (auto _v : V) {
        if (!C[v][_v]) {
          flg = false;
          break;
        }
      }
    }
    if (flg) {
      res = max(res, (int)V.size());
    }
  }
  printf("%d\n", res);
}