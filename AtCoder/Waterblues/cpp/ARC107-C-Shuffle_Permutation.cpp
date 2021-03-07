#include <bits/stdc++.h>
#define MAX_N 50
#define MOD 998244353
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N][MAX_N];

ll par[MAX_N], rnk[MAX_N];

void init() {
  for (ll i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y])
    par[x] = y;
  else {
    par[y] = x;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  init();
  for (ll i = 0; i < N - 1; ++i) {
    for (ll j = i + 1; j < N; ++j) {
      bool f = true;
      for (ll k = 0; k < N; ++k) {
        if (A[i][k] + A[j][k] > K) f = false;
      }
      if (f) unite(i, j);
    }
  }
  map<ll, ll> C;
  for (ll i = 0; i < N; ++i) {
    ++C[find(i)];
  }
  ll res = 1;
  for (auto p : C) {
    for (ll i = 1; i <= p.second; ++i) {
      res = res * i % MOD;
    }
  }
  init();
  for (ll i = 0; i < N - 1; ++i) {
    for (ll j = i + 1; j < N; ++j) {
      bool f = true;
      for (ll k = 0; k < N; ++k) {
        if (A[k][i] + A[k][j] > K) f = false;
      }
      if (f) unite(i, j);
    }
  }
  C = map<ll, ll>();
  for (ll i = 0; i < N; ++i) {
    ++C[find(i)];
  }
  for (auto p : C) {
    for (ll i = 1; i <= p.second; ++i) {
      res = res * i % MOD;
    }
  }
  printf("%lld\n", res);
}