#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll P = 187963;
const ll Q = 163841;
const ll M = P * Q;
const ll K = 48611;

map<ll, ll> prime_factorize(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n > 1) res[n] = 1;
  return res;
}

ll mod_pow(__int128_t x, __int128_t n, __int128_t m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return (ll)res;
}

ll extgcd(ll a, ll b, ll &u, ll &v) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, v, u);
    v -= (a / b) * u;
  } else {
    u = 1, v = 0;
  }
  return d;
}

ll pos(ll x, ll m) {
  x %= m;
  return (x + m) % m;
}

ll mod_inv(ll x, ll m) {
  ll u, v;
  extgcd(x, m, u, v);
  return pos(u, m);
}

ll phi(ll n) {
  map<ll, ll> ps = prime_factorize(n);
  ll res = n;
  for (auto p : ps) {
    res = res / p.first * (p.first - 1);
  }
  return res;
}

ll solve(ll k, ll b, ll m) {
  // solve x^k = b (mod m) and return x
  ll ms = phi(m);
  ll u = mod_inv(k, ms);
  return mod_pow(b, u, m);
}

vector<ll> solve_bs(ll k, ll m, const vector<ll> &bs) {
  vector<ll> res;
  for (auto b : bs) {
    res.push_back(solve(k, b, m));
  }
  return res;
}

ll _encrypt(char c) {
  return mod_pow(c, K, M);
}

vector<ll> encrypt(string msg) {
  vector<ll> chi;
  for (auto c : msg) {
    chi.push_back(_encrypt(c));
  }
  return chi;
}

string decrypt(vector<ll> chi) {
  vector<ll> decrypted = solve_bs(K, M, chi);
  string msg;
  for (auto v : decrypted) {
    msg += v;
  }
  return msg;
}

int main() {
  string msg = "'Friendly Introduction to Number Theory'";
  vector<ll> chi = encrypt(msg);
  // for (auto v : chi)
  //   printf("%lld\n", v);
  string dec = decrypt(chi);
  puts(dec.c_str()); // 'Friendly Introduction to Number Theory'
}
