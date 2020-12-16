#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll X[MAX_N];
ll _X[MAX_N];

void solve() {
  for (int i = 0; i < N; ++i) {
    _X[i] = X[i];
  }
  sort(_X, _X + N);
  ll md1 = (N - 1) / 2;
  ll md2 = (N - 1) / 2 + 1;
  for (int i = 0; i < N; ++i) {
    ll res;
    if (X[i] <= _X[md1]) {
      res = _X[md2];
    } else {
      res = _X[md1];
    }
    printf("%lld\n", res);
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  solve();
}