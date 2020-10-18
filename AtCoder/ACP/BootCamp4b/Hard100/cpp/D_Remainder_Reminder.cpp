#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

ll N, K;

int main() {
  cin >> N >> K;
  ll ans = 0;
  for (ll i = K + 1; i <= N; ++i) {
    ll p = N / i;
    ll q = i - K;
    ans += p * q + max(0LL, N - (p * i + K) + (K != 0));
  }
  printf("%lld\n", ans);
}