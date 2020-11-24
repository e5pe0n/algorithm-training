#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N, D;
double X[MAX_N], Y[MAX_N];

void solve() {
  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (sqrt(X[i] * X[i] + Y[i] * Y[i]) <= D) {
      ++res;
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N >> D;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  solve();
}