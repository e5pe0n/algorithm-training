#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  sort(A, A + N);
  ll mid_idx = N / 2;
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += abs(A[i] - A[mid_idx]);
  }
  if (N % 2 == 0) {
    ll t = 0;
    for (ll i = 0; i < N; ++i) {
      t += abs(A[i] - A[mid_idx + 1]);
    }
    res = min(res, t);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] -= i + 1;
  }
  solve();
}