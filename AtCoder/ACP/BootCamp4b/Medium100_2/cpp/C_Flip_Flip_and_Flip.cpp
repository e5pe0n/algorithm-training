#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

void solve() {
  ll res = 0;
  if (N > M) {
    swap(N, M);
  }
  if (N == 1 && M == 1) {
    res = 1;
  } else if (N == 2) {
    res = 0;
  } else {
    res = max(1LL, N - 2) * max(1LL, M - 2);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  solve();
}