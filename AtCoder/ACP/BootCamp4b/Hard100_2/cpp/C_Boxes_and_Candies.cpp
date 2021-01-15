#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, X;
ll A[MAX_N];

void solve() {
  ll res = 0;
  for (ll i = 0; i < N - 1; ++i) {
    ll d = A[i] + A[i + 1] - X;
    res += max(0LL, d);
    if (d > 0) { A[i + 1] = max(0LL, A[i + 1] - d); }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> X;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}