#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N + 1];

void solve() {
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    ll t = (A[i] + A[i + 1]) / 2;
    res += t;
    A[i + 1] -= max(0LL, t * 2 - A[i]);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}