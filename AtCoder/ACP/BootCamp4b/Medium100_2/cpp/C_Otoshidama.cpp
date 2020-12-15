#include <bits/stdc++.h>
using namespace std;

int N, Y;

void solve() {
  int NA = Y / 10000;
  int NB = Y / 5000;
  for (int i = 0; i <= NA; ++i) {
    for (int j = 0; j <= NB; ++j) {
      int k = (Y - 10000 * i - 5000 * j) / 1000;
      if (k >= 0 && i + j + k == N) {
        printf("%d %d %d\n", i, j, k);
        return;
      }
    }
  }
  printf("-1 -1 -1\n");
}

int main() {
  cin >> N >> Y;
  solve();
}