#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_S = 100;
ll S, T;

int main() {
  cin >> S >> T;
  ll res = 0;
  for (ll a = 0; a <= MAX_S; ++a) {
    for (ll b = 0; b <= MAX_S; ++b) {
      for (ll c = 0; c <= MAX_S; ++c) {
        if (a + b + c <= S && a * b * c <= T) ++res;
      }
    }
  }
  printf("%lld\n", res);
}