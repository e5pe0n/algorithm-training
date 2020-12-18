#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K, S;

void solve() {
  ll res = 0;
  for (ll x = 0; x <= K; ++x) {
    for (ll y = 0; y <= K; ++y) {
      ll z = S - x - y;
      if (0 <= z && z <= K) {
        ++res;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> K >> S;
  solve();
}