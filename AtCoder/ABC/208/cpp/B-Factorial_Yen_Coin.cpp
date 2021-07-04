#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll P;

int main() {
  cin >> P;
  vector<ll> parms{1};
  for (ll i = 1; i < 15; ++i) {
    parms.push_back(parms[i - 1] * i);
  }
  ll res = 0;
  for (ll i = 14; i > 0; --i) {
    res += min(P / parms[i], 100LL);
    P %= parms[i];
  }
  printf("%lld\n", res);
}