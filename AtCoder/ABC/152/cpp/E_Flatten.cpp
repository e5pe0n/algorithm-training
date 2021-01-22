#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 10000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

map<ll, ll> factorize(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    ll cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    res[i] = cnt;
  }
  if (n > 1) res[n] = 1;
  return res;
}

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) { res = res * x % MOD; }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll inv(ll x) {
  return mod_pow(x, MOD - 2);
}

void solve() {
  ll res = 0;
  map<ll, ll> C;
  for (ll i = 0; i < N; ++i) {
    map<ll, ll> D = factorize(A[i]);
    for (auto p : D) {
      C[p.first] = max(C[p.first], p.second);
    }
  }
  ll lcm = 1;
  for (auto p : C) {
    lcm = lcm * mod_pow(p.first, p.second) % MOD;
  }
  for (ll i = 0; i < N; ++i) {
    res = (res + lcm * inv(A[i]) % MOD) % MOD;
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