#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;

void solve() {
  ll res = 0;
  for (ll b = K + 1; b <= N; ++b) {
    ll p = N / b;
    ll q = b - K;
    res += p * q + max(0LL, N - (p * b + K) + (K != 0));
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  solve();
}