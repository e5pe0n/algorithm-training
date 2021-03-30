#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef chrono::high_resolution_clock hrc;

vector<ll> pollard_rho(ll n) {
  ll iter = 1000;
  auto now = hrc::now().time_since_epoch().count();
  default_random_engine generator(now);
  uniform_int_distribution<ll> distribution(0, n - 1);
  ll x = distribution(generator);
  ll y = x;
  ll k = 2;
  set<ll> res;
  for (ll i = 0; i < iter; ++i) {
    x = ((x * x - 1) + n) % n;
    ll d = __gcd(((y - x) + n) % n, n);
    if (d != 1 && d != n) res.insert(d);
    if (i == k) {
      y = x;
      k *= 2;
    }
  }
  return vector<ll>(res.begin(), res.end());
}

int main() {
  for (ll i = 0; i < 10; ++i) {
    vector<ll> res = pollard_rho(1387);
    for (ll i = 0; i < res.size(); ++i) {
      printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
    }
  }
}

// 19
// 19 73
// 19
// 19 73
// 19
// 19
// 19
// 19 73
// 19 73
// 19