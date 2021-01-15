#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

void solve() {
  ll N = S.size();
  ll res = 0;
  for (ll i = 0; i < 1 << (N - 1); ++i) {
    ll t = 0;
    ll a = 0;
    for (ll j = 0; j < N - 1; ++j) {
      a += S[j] - '0';
      if (i >> j & 1) {
        t += a;
        a = 0;
      } else {
        a *= 10;
      }
    }
    a += S[N - 1] - '0';
    t += a;
    res += t;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S;
  solve();
}