#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N, S, K;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

int main() {
  cin >> T;
  for (int _ = 0; _ < T; ++_) {
    cin >> N >> S >> K;
    ll M = N - S;
    ll d = __gcd(K, __gcd(M, N));
    K /= d;
    M /= d;
    N /= d;
    ll res;
    if (__gcd(K, N) == 1) {
      ll _K = 0;
      ll y = 0;
      extgcd(K, N, _K, y);
      res = _K * M;
      res %= N;
      res = (res + N) % N;
    } else {
      res = -1;
    }
    printf("%lld\n", res);
  }
}