#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 100
using namespace std;

int N;
int X[MAX_N];

void solve() {
  int res = INF;
  for (int x = 1; x <= 100; ++x) {
    int t = 0;
    for (int i = 0; i < N; ++i) {
      t += (X[i] - x) * (X[i] - x);
    }
    res = min(res, t);
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  solve();
}