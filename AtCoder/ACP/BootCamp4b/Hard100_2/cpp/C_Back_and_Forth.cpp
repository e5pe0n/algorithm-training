#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sx, sy, tx, ty;

void solve() {
  for (int y = sy; y < ty; ++y) {
    printf("U");
  }
  for (int x = sx; x <= tx; ++x) {
    printf("R");
  }
  for (int y = ty; y >= sy; --y) {
    printf("D");
  }
  for (int x = tx + 1; x > sx; --x) {
    printf("L");
  }
  printf("UL");
  for (int y = sy; y <= ty; ++y) {
    printf("U");
  }
  for (int x = sx - 1; x < tx; ++x) {
    printf("R");
  }
  for (int y = ty + 1; y > sy; --y) {
    printf("D");
  }
  for (int x = tx; x > sx; --x) {
    printf("L");
  }
  printf("\n");
}

int main() {
  cin >> sx >> sy >> tx >> ty;
  solve();
}