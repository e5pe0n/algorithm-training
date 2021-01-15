#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

void solve() {
  ll res = 0;
  for (ll i = A; i < (A + 4 - 1) / 4 * 4; ++i) {
    res ^= i;
  }
  for (ll i = B / 4 * 4; i <= B; ++i) {
    res ^= i;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> A >> B;
  solve();
}