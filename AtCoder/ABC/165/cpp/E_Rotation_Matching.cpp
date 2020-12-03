#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_M 200'000
using namespace std;

int N, M;
int P[MAX_M][2];

void solve() {
  int w = M - 2;
  int _w = w;
  for (int i = 0; i < M / 2; ++i) {
    P[i][0] = i + 1;
    P[i][1] = i + 1 + _w + 1;
    _w -= 2;
  }
  _w = w + 1;
  for (int i = 0; i < M - M / 2; ++i) {
    P[i + M / 2][0] = M + i + 1;
    P[i + M / 2][1] = M + i + 1 + _w + 1;
    _w -= 2;
  }
  for (int i = 0; i < M; ++i) {
    printf("%d %d\n", P[i][0], P[i][1]);
  }
}

int main() {
  cin >> N >> M;
  solve();
}