#include <bits/stdc++.h>
#define MAX_N 100'000
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N, K;
ll X[MAX_N + 1];

void solve() {
  ll res = INF;
  for (int i = 0; i + K - 1 < N; ++i) {
    if (X[i] * X[i + K - 1] >= 0) {
      res = min(res, max(abs(X[i]), abs(X[i + K - 1])));
    } else {
      res = min(res, -X[i] + X[i + K - 1] + min(abs(X[i]), X[i + K - 1]));
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  solve();
}