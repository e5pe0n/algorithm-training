#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_W = 500'000;
const ll MAX_N = 250'000;
ll W, N;
ll L[MAX_N], R[MAX_N];
ll H[MAX_W + 1];
ll res[MAX_N];

int main() {
  cin >> W >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
  }
  for (ll i = 0; i < N; ++i) {
    ll max_h = 0;
    for (ll j = L[i]; j <= R[i]; ++j) {
      max_h = max(max_h, H[j]);
    }
    res[i] = max_h + 1;
    for (ll j = L[i]; j <= R[i]; ++j) {
      H[j] = max_h + 1;
    }
  }
  for (ll i = 0; i < N; ++i) {
    printf("%lld\n", res[i]);
  }
}