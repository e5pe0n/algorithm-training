#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int X, N;
int p[MAX_N + 2];

void solve() {
  sort(p + 1, p + N + 1);
  p[0] = -1;
  p[N + 1] = 102;
  int d = 101;
  int res = 0;
  for (int i = 0; i + 1 < N + 2; ++i) {
    for (int j = p[i] + 1; j < p[i + 1]; ++j) {
      if (abs(j - X) < d) {
        d = abs(j - X);
        res = j;
      }
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> X >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> p[i];
  }
  solve();
}