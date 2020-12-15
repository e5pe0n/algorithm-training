#include <bits/stdc++.h>
#define MAX_M 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll X[MAX_M];
ll dx[MAX_M];

void solve() {
  if (M == 1 || N >= M) {
    puts("0");
    return;
  }
  sort(X, X + M);
  for (int i = 0; i < M - 1; ++i) {
    dx[i] = X[i + 1] - X[i];
  }
  sort(dx, dx + M - 1);
  ll res = 0;
  for (int i = 0; i < M - 1 - (N - 1); ++i) {
    res += dx[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> X[i];
  }
  solve();
}