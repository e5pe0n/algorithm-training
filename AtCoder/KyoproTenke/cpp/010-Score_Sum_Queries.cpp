#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
ll N;
ll C[MAX_N], P[MAX_N];
ll C1[MAX_N + 1], C2[MAX_N + 2];
ll Q;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> C[i] >> P[i];
  }
  for (ll i = 0; i < N; ++i) {
    C1[i + 1] = C1[i];
    C2[i + 1] = C2[i];
    if (C[i] == 1)
      C1[i + 1] += P[i];
    else
      C2[i + 1] += P[i];
  }
  cin >> Q;
  while (Q--) {
    ll L, R;
    cin >> L >> R;
    printf("%lld %lld\n", C1[R] - C1[L - 1], C2[R] - C2[L - 1]);
  }
}