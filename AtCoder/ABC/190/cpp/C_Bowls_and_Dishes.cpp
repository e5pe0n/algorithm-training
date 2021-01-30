#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 100
#define MAX_K 16
using namespace std;
typedef long long ll;

ll N, M, K;
ll A[MAX_M], B[MAX_M];
ll C[MAX_K], D[MAX_K];

void solve() {
  ll res = 0;
  for (ll i = 0; i < 1 << K; ++i) {
    ll t = 0;
    map<ll, ll> cnt;
    for (ll j = 0; j < K; ++j) {
      if (i >> j & 1) {
        ++cnt[C[j]];
      } else {
        ++cnt[D[j]];
      }
    }
    for (ll i = 0; i < M; ++i) {
      if (cnt[A[i]] > 0 && cnt[B[i]] > 0) ++t;
    }
    res = max(res, t);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  cin >> K;
  for (ll i = 0; i < K; ++i) {
    cin >> C[i] >> D[i];
    --C[i];
    --D[i];
  }
  solve();
}