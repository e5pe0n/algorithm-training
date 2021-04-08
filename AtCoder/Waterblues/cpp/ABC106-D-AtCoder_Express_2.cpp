#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
typedef long long ll;

ll N, M, Q;
ll Li[MAX_N + 1], Ri[MAX_N + 1];
ll cnt[MAX_N + 1][MAX_N + 1];
ll C[MAX_N + 1][MAX_N + 1];

int main() {
  cin >> N >> M >> Q;
  for (ll i = 0; i < M; ++i) {
    ll L, R;
    cin >> L >> R;
    ++Li[L], ++Ri[R];
    ++C[L][R];
  }
  ll ML = M;
  for (ll i = 1; i <= N; ++i) {
    ll MR = ML;
    for (ll j = N; j >= i; --j) {
      cnt[i][j] = MR;
      MR = max(0LL, MR - Ri[j]);
    }
    ML = max(0LL, ML - Li[i]);
    for (ll j = i; j <= N; ++j) {
      Ri[j] -= C[i][j];
    }
  }
  while (Q--) {
    ll p, q;
    cin >> p >> q;
    printf("%lld\n", cnt[p][q]);
  }
}