#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
const ll MAX_X = 1000;
const ll MAX_Y = 1000;
ll N;
ll lxs[MAX_N], lys[MAX_N], rxs[MAX_N], rys[MAX_N];
ll cnt[MAX_X + 1][MAX_Y + 1];
ll A[MAX_N + 1];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> lxs[i] >> lys[i] >> rxs[i] >> rys[i];
  }

  for (ll i = 0; i < N; ++i) {
    ++cnt[lxs[i]][lys[i]];
    --cnt[lxs[i]][rys[i]];
    --cnt[rxs[i]][lys[i]];
    ++cnt[rxs[i]][rys[i]];
  }
  for (ll i = 0; i <= MAX_X; ++i) {
    for (ll j = 1; j <= MAX_Y; ++j) {
      cnt[i][j] += cnt[i][j - 1];
    }
  }
  for (ll j = 0; j <= MAX_Y; ++j) {
    for (ll i = 1; i <= MAX_X; ++i) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }
  for (ll i = 0; i <= MAX_X; ++i) {
    for (ll j = 0; j <= MAX_Y; ++j) {
      if (cnt[i][j] >= 1) ++A[cnt[i][j]];
    }
  }
  for (ll i = 1; i <= N; ++i) {
    printf("%lld\n", A[i]);
  }
}