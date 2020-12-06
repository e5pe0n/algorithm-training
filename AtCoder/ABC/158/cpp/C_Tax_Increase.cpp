#include <bits/stdc++.h>
using namespace std;

int A, B;

void solve() {
  int min_a = (int)ceil(A * 100.0 / 8);
  int max_a = (int)(ceil((A + 1) * 100.0 / 8)) - 1;
  int min_b = B * 10;
  int max_b = (B + 1) * 10 - 1;
  int res = -1;
  for (int a = min_a; a <= max_a; ++a) {
    for (int b = min_b; b <= max_b; ++b) {
      if (a == b) {
        printf("%d\n", a);
        return;
      }
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> A >> B;
  solve();
}