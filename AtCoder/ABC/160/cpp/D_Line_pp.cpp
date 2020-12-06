#include <bits/stdc++.h>
#define MAX_N 2000
using namespace std;

int N, X, Y;
int cnt[MAX_N];

void solve() {
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      int d = min(i - j, abs(X - j) + abs(Y - i) + 1);
      ++cnt[d];
    }
  }
  for (int i = 1; i < N; ++i) {
    printf("%d\n", cnt[i]);
  }
}

int main() {
  cin >> N >> X >> Y;
  --X;
  --Y;
  solve();
}