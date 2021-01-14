#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  for (ll n = 1; n <= 3500; ++n) {
    for (ll w = 1; w <= 3500; ++w) {
      ll p = N * n * w;
      ll q = 4 * n * w - N * (w + n);
      if (q > 0 && p % q == 0) {
        ll h = p / q;
        printf("%lld %lld %lld\n", h, n, w);
        return;
      }
    }
  }
}

int main() {
  cin >> N;
  solve();
}
