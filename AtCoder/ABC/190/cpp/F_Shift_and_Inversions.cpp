#include <bits/stdc++.h>
#define MAX_N 300'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll bit[MAX_N + 1];

ll sum(ll i) {
  ll s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i; // minus last 1 bit
  }
  return s;
}

void add(ll i, ll x) {
  while (i <= N) {
    bit[i] += x;
    i += i & -i; // plus last 1 bit
  }
}

void solve() {
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += i - sum(A[i]);
    add(A[i], 1);
  }
  printf("%lld\n", res);
  for (ll i = 0; i < N - 1; ++i) {
    res = res - (A[i] - 1) + (N - A[i]);
    printf("%lld\n", res);
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    ++A[i];
  }
  solve();
}