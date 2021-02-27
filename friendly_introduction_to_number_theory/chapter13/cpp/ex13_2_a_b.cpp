#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> sieve(ll n) {
  vector<ll> res;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
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

int main() {
  vector<ll> primes = sieve(100);
  for (ll i = 0; i < primes.size(); ++i) {
    printf("%lld%c", primes[i], i == primes.size() - 1 ? '\n' : ' ');
  }
  for (ll i = 70; i <= 100; i += 2) {
    for (ll _i = 0; _i < primes.size() - 1; ++_i) {
      for (ll _j = _i + 1; _j < primes.size(); ++_j) {
        if (primes[_i] + primes[_j] == i)
          printf("%lld = %lld + %lld\n", i, primes[_i], primes[_j]);
      }
    }
  }
}