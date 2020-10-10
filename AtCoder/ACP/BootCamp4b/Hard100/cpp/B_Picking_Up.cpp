#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>

#define MAX_N 50

using namespace std;

int X[MAX_N]{};
int Y[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  map<vector<int>, int> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i != j) {
        int dx = X[i] - X[j];
        int dy = Y[i] - Y[j];
        ++M[vector<int>{dx, dy}];
      }
    }
  }
  int cnt = 0;
  for (auto m : M) {
    cnt = max(cnt, m.second);
  }
  printf("%d\n", N - cnt);
}