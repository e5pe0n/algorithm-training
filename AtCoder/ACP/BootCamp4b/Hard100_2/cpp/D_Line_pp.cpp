#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, X, Y;

void solve() {
  ll res = 0;
  map<ll, ll> C;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int d = min(j - i, abs(X - i) + abs(Y - j) + 1);
      ++C[d];
    }
  }
  for (int i = 1; i < N; ++i) {
    printf("%lld\n", C[i]);
  }
}

int main() {
  cin >> N >> X >> Y;
  --X;
  --Y;
  solve();
}