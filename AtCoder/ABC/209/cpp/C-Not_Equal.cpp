#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll MAX_N = 200'000;

ll N;
ll C[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> C[i];
  }
  sort(C, C + N);
  ll res = 1;
  for (ll i = 0; i < N; ++i) {
    res = res * max(0LL, (C[i] - i)) % MOD;
  }
  printf("%lld\n", res);
}