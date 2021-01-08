#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

void solve() {
  ll res = 1;
  ll p = M / N;
  for (p; p > 0; --p) {
    ll q = M % p;
    if (q % p == 0) {
      res = p;
      break;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  solve();
}