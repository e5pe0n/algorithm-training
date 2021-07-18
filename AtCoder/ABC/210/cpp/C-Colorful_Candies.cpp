#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 300'000;

ll N, K;
ll C[MAX_N];

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> C[i];
  }
  ll idx = 0;
  ll uniques = 0;
  map<ll, ll> cnt;
  while (idx < K) {
    if (cnt[C[idx]] == 0) ++uniques;
    ++cnt[C[idx++]];
  }
  ll res = uniques;
  for (ll i = idx; i < N; ++i) {
    if (--cnt[C[i - K]] == 0) --uniques;
    if (cnt[C[i]]++ == 0) ++uniques;
    res = max(res, uniques);
  }
  printf("%lld\n", res);
}