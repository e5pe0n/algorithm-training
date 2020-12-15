#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_X 1'000'000'000
using namespace std;
typedef long long ll;

ll N, X;
ll x[MAX_N];
ll dx[MAX_N];

void solve() {
  sort(x, x + N);
  for (int i = 0; i < N - 1; ++i) {
    dx[i] = x[i + 1] - x[i];
  }
  ll g = dx[0];
  for (int i = 1; i < N - 1; ++i) {
    g = __gcd(g, dx[i]);
  }
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    res = max(res, __gcd(g, abs(x[i] - X)));
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> X;
  for (int i = 0; i < N; ++i) {
    cin >> x[i];
  }
  solve();
}