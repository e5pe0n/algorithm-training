#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll K;

void solve() {
  ll cnt = 0;
  for (ll d = 1; d < INF; ++d) {
    vector<ll> ub(d, 9);
    vector<ll> n(d, 1);
    ll i = 0;
    while (n[0] < 10) {
      if (n[i] > ub[i]) {
        ++n[i - 1];
        --i;
        continue;
      }
      if (i == d - 1) {
        cnt += 1;
        if (cnt == K) {
          for (ll j = 0; j < d; ++j) {
            printf("%lld", n[j]);
          }
          printf("\n");
          return;
        }
        ++n[i];
        continue;
      }
      while (i < d - 1) {
        ub[i + 1] = min(9LL, n[i] + 1);
        n[i + 1] = max(0LL, n[i] - 1);
        i += 1;
      }
    }
  }
}

int main() {
  cin >> K;
  solve();
}