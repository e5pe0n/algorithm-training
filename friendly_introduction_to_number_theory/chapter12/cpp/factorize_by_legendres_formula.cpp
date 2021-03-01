#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> sieve(ll n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<ll> res;
  for (ll i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      res.push_back(i);
      for (ll j = i + i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return res;
}

map<ll, ll> legendre(ll n) {
  // return factors of n! using legendre's formula
  // O(n log n)
  map<ll, ll> res;
  vector<ll> ps = sieve(n);
  for (auto v : ps) {
    ll p = v;
    while (p <= n) {
      res[v] += n / p;
      p *= v;
    }
  }
  return res;
}

void solve(ll n) {
  map<ll, ll> res = legendre(n);
  printf("%lld!={", n);
  for (auto it = res.begin(); it != res.end(); ++it) {
    printf(
        "%lld: %lld%s", it->first, it->second, it == --res.end() ? "" : ", ");
  }
  puts("}");
}

int main() {
  solve(10); // 10!={2: 8, 3: 4, 5: 2, 7: 1}
  solve(15); // 15!={2: 11, 3: 6, 5: 3, 7: 2, 11: 1, 13: 1}
  solve(20); // 20!={2: 18, 3: 8, 5: 4, 7: 2, 11: 1, 13: 1, 17: 1, 19: 1}
}