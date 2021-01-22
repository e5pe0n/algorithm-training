// O (A log log A + N log A)
#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 10000
#define MAX_A 1'000'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

vector<bool> is_prime;
vector<ll> min_factor;

// A log log A
void sieve() {
  is_prime = vector<bool>(MAX_A + 1, true);
  is_prime[0] = is_prime[1] = false;
  min_factor = vector<ll>(MAX_A + 1, -1);
  for (ll i = 2; i <= MAX_A; ++i) {
    if (is_prime[i]) {
      min_factor[i] = i;
      for (ll j = i + i; j <= MAX_A; j += i) {
        is_prime[j] = false;
        if (min_factor[j] == -1) min_factor[j] = i;
      }
    }
  }
}

// log A
map<ll, ll> factorize(ll n) {
  map<ll, ll> res;
  while (n != 1) {
    ll p = min_factor[n];
    ll cnt = 0;
    while (min_factor[n] == p) {
      ++cnt;
      n /= p;
    }
    res[p] = cnt;
  }
  return res;
}

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll inv(ll x) {
  return mod_pow(x, MOD - 2);
}

void solve() {
  sieve();
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
  ll res = 0;
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