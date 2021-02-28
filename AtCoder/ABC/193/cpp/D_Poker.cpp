#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;
string S, T;

ll f(string S) {
  map<ll, ll> C;
  for (auto c : S) {
    ++C[c - '0'];
  }
  ll res = 0;
  for (ll i = 1; i <= 9; ++i) {
    res += i * ((ll)pow(10, C[i]));
  }
  return res;
}

int main() {
  cin >> K >> S >> T;
  map<ll, ll> C;
  for (ll i = 1; i <= 9; ++i) {
    C[i] = K;
  }
  for (ll i = 0; i < 4; ++i) {
    --C[S[i] - '0'];
    --C[T[i] - '0'];
  }
  ll cnt = 0;
  ll t = 0;
  for (ll i = 1; i <= 9; ++i) {
    for (ll j = 1; j <= 9; ++j) {
      map<ll, ll> _C = C;
      --_C[i];
      --_C[j];
      if (_C[i] >= 0 && _C[j] >= 0) {
        ll tS = f(S.substr(0, 4) + to_string(i));
        ll tT = f(T.substr(0, 4) + to_string(j));
        ll x = C[i] * (C[j] - (i == j));
        if (tS > tT) cnt += x;
        t += x;
      }
    }
  }
  printf("%.7f\n", (double)cnt / t);
}