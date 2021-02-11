#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 50
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll res = -INF;
  for (ll i = 0; i < N; ++i) {
    ll max_a = -INF;
    ll idx_a = 0;
    for (ll j = 0; j < N; ++j) {
      if (i == j) continue;
      ll a = 0;
      for (ll k = min(i, j); k <= max(i, j); ++k) {
        if ((k - min(i, j)) % 2 != 0) { a += A[k]; }
      }
      if (max_a < a) {
        max_a = a;
        idx_a = j;
      }
    }
    ll t = 0;
    for (ll j = min(i, idx_a); j <= max(i, idx_a); ++j) {
      if ((j - min(i, idx_a)) % 2 == 0) t += A[j];
    }
    res = max(res, t);
  }
  printf("%lld\n", res);
}