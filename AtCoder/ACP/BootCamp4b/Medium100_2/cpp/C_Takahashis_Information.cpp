#include <bits/stdc++.h>
using namespace std;

int C[3][3];

void solve() {
  int cnt = 0;
  for (int i = 0; i < 3; ++i) {
    if (C[i][0] - C[(i + 1) % 3][0] == C[i][1] - C[(i + 1) % 3][1] &&
        C[i][1] - C[(i + 1) % 3][1] == C[i][2] - C[(i + 1) % 3][2]) {
      ++cnt;
    }
  }
  for (int j = 0; j < 3; ++j) {
    if (C[0][j] - C[0][(j + 1) % 3] == C[1][j] - C[1][(j + 1) % 3] &&
        C[1][j] - C[1][(j + 1) % 3] == C[2][j] - C[2][(j + 1) % 3]) {
      ++cnt;
    }
  }
  if (cnt == 6) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> C[i][j];
    }
  }
  solve();
}