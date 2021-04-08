#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef chrono::high_resolution_clock hrc;

pll calc_k_q(ll n) {
  ll k = 0;
  ll q = n - 1;
  while (q % 2 == 0) {
    ++k;
    q >>= 1;
  }
  return {k, q};
}

ll mod_pow(__int128_t x, __int128_t n, __int128_t m) {
  __int128_t res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

bool rabin_miller_test(ll n) {
  // return true if n is a composite number.
  ll iter = 10;
  auto now = hrc::now().time_since_epoch().count();
  default_random_engine generator(now);
  uniform_int_distribution<ll> distribution(2, n - 1);
  auto [k, q] = calc_k_q(n); // n - 1 = 2^k * q
  for (ll i = 0; i < iter; ++i) {
    ll a = distribution(generator);
    ll a_q = mod_pow(a, q, n);
    // (a) a^q not equiv 1 (mod n)
    if (a_q == 1) continue; // n is probably a prime number.

    // (b) a^(2^k)q not equiv -1 (mod n) for all k = 0, 1, 2, ..., k - 1
    bool composite = true;
    if (a_q == n - 1) continue; // n is probably a prime number.
    for (ll i = 1; i < k; ++i) {
      a_q = mod_pow(a_q, 2, n);
      if (a_q == n - 1) { // n is  a prime nubmer.
        composite = false;
        break;
      }
    }
    if (composite) return true;
  }
  return false;
}

int main() {
  vector<ll> vs{
      561,          // composite (carmichael)
      294409,       // composite
      172947529,    // composite
      12911,        // prime
      1000081,      // prime
      100000000069, // prime
  };
  for (auto v : vs) {
    printf("n=%lld is %s\n",
           v,
           rabin_miller_test(v) ? "composite" : "probably prime");
  }
}

// n=561 is composite
// n=294409 is composite
// n=172947529 is composite
// n=12911 is probably prime
// n=1000081 is probably prime
// n=100000000069 is probably prime