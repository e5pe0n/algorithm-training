#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;
typedef long long ll;

ll N, P;
ll A[MAX_N];

ll com(ll n, ll k) {
  if (n < 0 || k < 0 || n < k) {
    return 0;
  }
  if (k == 0) {
    return 1;
  }
  ll res = 1;
  for (ll i = 1; i <= k; ++i) {
    res = res * (n - i + 1) / i;
  }
  return res;
}

void solve() {
  ll odd = 0;
  ll even = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }
  ll t = 0;
  for (int i = 0; i <= even; ++i) {
    t += com(even, i);
  }
  ll res = 0;
  if (P) {
    for (int i = 1; i <= odd; i += 2) {
      res += com(odd, i) * t;
    }
  } else {
    for (int i = 0; i <= odd; i += 2) {
      res += com(odd, i) * t;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> P;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}