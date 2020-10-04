#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> V(N);
  for (int i = 0; i < N; ++i) {
    int X, L;
    cin >> X >> L;
    V[i] = vector<int>{X + L, X - L};
  }
  sort(V.begin(), V.end());
  int end = V[0][0];
  int cnt = 1;
  for (int i = 1; i < N; ++i) {
    if (end <= V[i][1]) {
      ++cnt;
      end = V[i][0];
    }
  }
  printf("%d\n", cnt);
}