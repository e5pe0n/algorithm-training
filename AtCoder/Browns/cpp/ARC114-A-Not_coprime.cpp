#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_X 50
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N;
ll X[MAX_N];

vector<ll> primes() {
  vector<ll> res;
  vector<bool> is_prime(MAX_X + 1, true);
  for (ll i = 2; i <= MAX_X; ++i) {
    if (is_prime[i]) {
      res.push_back(i);
      for (ll j = i + i; j <= MAX_X; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return res;
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> X[i];
  }
  vector<ll> ps = primes();
  ll res = INF;
  for (ll i = 1; i < (1 << ps.size()); ++i) {
    ll t = 1;
    for (ll j = 0; j < ps.size(); ++j) {
      if (i >> j & 1) t *= ps[j];
    }
    bool f = true;
    for (ll j = 0; j < N; ++j) {
      if (__gcd(t, X[j]) == 1) {
        f = false;
        break;
      }
    }
    if (f) res = min(res, t);
  }
  printf("%lld\n", res);
}