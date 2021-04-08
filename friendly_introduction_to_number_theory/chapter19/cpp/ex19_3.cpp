#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> gen_primes(ll n) {
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

bool is_carmichael(ll n, vector<ll> ps) {
  bool res = false;
  for (ll i = 1; i < ps.size(); ++i) { // ps[0] = 2 is not an odd prime.
    ll p = ps[i];
    if (n % p == 0) {
      if (n % (p * p) != 0 && (n - 1) % (p - 1) == 0)
        res = true;
      else {
        res = false;
        break;
      }
    }
  }
  return res;
}

int main() {
  vector<ll> ps = gen_primes(200'000);
  vector<ll> ns{1105,
                1235,
                2821,
                6601,
                8911,
                10659,
                19747,
                105545,
                126217,
                162401,
                172081,
                188461};
  for (auto n : ns) {
    printf("n=%lld, is_carmichael=%s\n",
           n,
           is_carmichael(n, ps) ? "true" : "false");
  }
}

// n=1105, is_carmichael=true
// n=1235, is_carmichael=false
// n=2821, is_carmichael=true
// n=6601, is_carmichael=true
// n=8911, is_carmichael=true
// n=10659, is_carmichael=false
// n=19747, is_carmichael=false
// n=105545, is_carmichael=false
// n=126217, is_carmichael=true
// n=162401, is_carmichael=true
// n=172081, is_carmichael=true
// n=188461, is_carmichael=true