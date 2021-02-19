#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

int main() {
  cin >> N >> M;
  ll x = -1, y = -1, z = -1;
  for (ll j = 0; j <= M - 2 * N; ++j) {
    ll t = (M - 2 * N - j);
    if (t % 2 == 0) {
      ll k = t / 2;
      ll i = N - j - k;
      if (i >= 0) {
        x = i, y = j, z = k;
        break;
      }
    }
  }
  printf("%lld %lld %lld\n", x, y, z);
}