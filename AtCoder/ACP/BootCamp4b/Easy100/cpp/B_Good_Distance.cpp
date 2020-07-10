#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

#define MAX_N 10
#define MAX_D 10

using namespace std;

int X[MAX_N][MAX_D];
bool B[MAX_N]{};

int main() {
  int N, D;
  cin >> N >> D;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < D; ++j) {
      cin >> X[i][j];
    }
  }
  int cnt = 0;
  B[0] = true;
  B[1] = true;
  do {
    vector<int> v;
    for (int i = 0; i < N; ++i) {
      if (B[i])
        v.push_back(i);
    }
    int d = 0;
    for (int i = 0; i < D; ++i) {
      d += (X[v[0]][i] - X[v[1]][i]) * (X[v[0]][i] - X[v[1]][i]);
    }
    if (d == (int)(sqrt(d)) * (int)(sqrt(d))) {
      ++cnt;
    }
  } while (prev_permutation(B, B + N));
  printf("%d\n", cnt);
}