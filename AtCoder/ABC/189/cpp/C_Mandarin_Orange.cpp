#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    ll min_a = A[i];
    for (ll j = i; j < N; ++j) {
      min_a = min(min_a, A[j]);
      res = max(res, min_a * (j - i + 1));
    }
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