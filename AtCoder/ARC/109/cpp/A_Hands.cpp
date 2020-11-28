#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;

int a, b, x, y;

void solve() {
  if (a == b) {
    printf("%d\n", x);
    return;
  }
  int res = INF;
  if (a < b) {
    for (int i = 0; i < b - a + 1; ++i) {
      res = min(res, (2 * i + 1) * x + (b - a - i) * y);
    }
  } else {
    for (int i = 0; i < a - b; ++i) {
      res = min(res, (2 * i + 1) * x + (a - b - 1 - i) * y);
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> a >> b >> x >> y;
  solve();
}