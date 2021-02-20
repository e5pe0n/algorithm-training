#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;

ll g1(ll n) {
  string s = to_string(n);
  sort(s.rbegin(), s.rend());
  return stoll(s);
}

ll g2(ll n) {
  string s = to_string(n);
  sort(s.begin(), s.end());
  return stoll(s);
}

ll f(ll n) {
  return g1(n) - g2(n);
}

int main() {
  cin >> N >> K;
  ll res = N;
  for (ll i = 0; i < K; ++i) {
    res = f(res);
  }
  printf("%lld\n", res);
}