#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<vector<ll>, vector<ll>> pvv;

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

pvv gen_QRs_and_NRs(ll n) {
  ll b = 0;
  for (ll i = 0; i < n; ++i) {
    b |= 1 << (i * i % n);
  }
  vector<ll> qrs, nrs;
  for (ll i = 0; i < n; ++i) {
    if (b & (1 << i))
      qrs.push_back(i);
    else
      nrs.push_back(i);
  }
  return {qrs, nrs};
}

int main() {
  vector<ll> ps = gen_primes(20);
  for (ll i = 1; i < ps.size(); ++i) {
    auto [qrs, nrs] = gen_QRs_and_NRs(ps[i]);
    ll A = accumulate(qrs.begin(), qrs.end(), 0);
    ll B = accumulate(nrs.begin(), nrs.end(), 0);
    printf("A%%%lld=%lld, B%%%lld=%lld\n", ps[i], A % ps[i], ps[i], B % ps[i]);
  }
}