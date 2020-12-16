#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

void solve() {
  ll res;
  if (N <= M / 2) {
    res = (N + M / 2) / 2;
  } else {
    res = M / 2;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  solve();
}