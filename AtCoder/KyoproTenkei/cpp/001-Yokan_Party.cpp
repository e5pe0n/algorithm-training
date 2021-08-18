#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 1e6;
ll N, L, K;
ll A[MAX_N + 1];
ll D[MAX_N];

int main() {
  cin >> N >> L >> K;
  A[0] = 0;
  for (ll i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  A[N + 1] = L;
  for (ll i = 0; i <= N; ++i) {
    D[i] = A[i + 1] - A[i];
  }
  ll lb = 0;
  ll ub = L;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    ll k = 0;
    ll partial_length = 0;
    for (ll i = 0; i <= N; ++i) {
      partial_length += D[i];
      if (partial_length >= mid) {
        ++k;
        partial_length = 0;
      }
    }
    if (k >= K + 1)
      lb = mid;
    else
      ub = mid;
  }
  printf("%lld\n", lb);
}