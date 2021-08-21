#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 10'000'000;
ll N, K;
ll cnt[MAX_N + 1];

int main() {
  cin >> N >> K;
  for (ll i = 2; i <= N; ++i) {
    if (cnt[i] != 0) continue;
    for (ll j = i; j <= N; j += i)
      ++cnt[j];
  }
  ll res = 0;
  for (ll i = 2; i <= N; ++i) {
    if (cnt[i] >= K) ++res;
  }
  printf("%lld\n", res);
}