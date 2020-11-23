#include <bits/stdc++.h>
using namespace std;

int r1, c1, r2, c2;

void solve() {
  if (r1 == r2 && c1 == c2) {
    printf("0\n");
    return;
  }
  if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3) {
    printf("1\n");
    return;
  }
  if ((r1 + c1 + r2 + c2) % 2 == 0 || abs(r1 - r2) + abs(c1 - c2) <= 6 || abs((r1 + c1) - (r2 + c2)) <= 3 ||
      abs((r1 - c1) - (r2 - c2)) <= 3) {
    printf("2\n");
    return;
  }
  printf("3\n");
}

int main() {
  cin >> r1 >> c1 >> r2 >> c2;
  solve();
}