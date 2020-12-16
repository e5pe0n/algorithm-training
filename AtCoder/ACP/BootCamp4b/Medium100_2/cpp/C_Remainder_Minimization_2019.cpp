#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;
typedef long long ll;

ll L, R;

void solve() {
  ll res = INF;
  if (R - L >= 2019) {
    res = 0;
  } else {
    for (ll i = L; i < R; ++i) {
      for (ll j = i + 1; j <= R; ++j) {
        res = min(res, i % 2019 * j % 2019 % 2019);
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> L >> R;
  solve();
}