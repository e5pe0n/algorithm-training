#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> gen_is_prime(ll n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      for (ll j = i + i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  return is_prime;
}

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

ll eval_ls(bool b, ll n) {
  if (b) return 1;
  return n % 2 == 0 ? 1 : -1;
}

ll calc_legendre_symbol(const ll &a,
                        const ll &p,
                        const ll &n,
                        const vector<bool> &is_prime) {
  if (a == p) return 1;

  if (a == 0) return 1;
  if (a == 1) return 1;
  if (a == -1) return eval_ls(p % 4 == 1, n);
  if (a == 2) return eval_ls(p % 8 == 1 || p % 8 == 7, n);
  if (a == -2) return eval_ls(p % 8 == 1 || p % 8 == 3, n);
  if (a == 3) return eval_ls(p % 12 == 1 || p % 12 == 11, n);
  if (a == -3) return eval_ls(p % 3 == 1, n);
  if (a == 5) return eval_ls(p % 5 == 1 || p % 5 == 4, n);
  if (a == -5) return eval_ls(p % 5 == 2 || p % 5 == -2, n);

  if (is_prime[a]) {
    ll t = calc_legendre_symbol(p % a, a, n, is_prime);
    return a % 4 == 1 || p % 4 == 1 ? t : -t;
  } else {
    map<ll, ll> ps = prime_factorize(a);
    ll res = 1;
    for (auto pr : ps) {
      res *= calc_legendre_symbol(pr.first, p, n * pr.second, is_prime);
    }
    return res;
  }
}

int main() {
  vector<bool> is_prime = gen_is_prime(1'000'000);
  printf("%lld\n", calc_legendre_symbol(14, 137, 1, is_prime));      // 1
  printf("%lld\n", calc_legendre_symbol(55, 179, 1, is_prime));      // -1
  printf("%lld\n", calc_legendre_symbol(299, 397, 1, is_prime));     // -1
  printf("%lld\n", calc_legendre_symbol(37603, 48611, 1, is_prime)); // 1
}