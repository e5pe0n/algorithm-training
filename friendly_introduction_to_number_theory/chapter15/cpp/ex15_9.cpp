#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

ll _pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}

ll sigma_p(ll p, ll k) {
  return ((ll)_pow(p, k + 1) - 1) / (p - 1);
}

ll sigma(ll n) {
  map<ll, ll> ps = prime_factorize(n);
  ll res = 1;
  for (auto p : ps) {
    res *= sigma_p(p.first, p.second);
  }
  return res;
}

ll s(ll n) {
  return sigma(n) - n;
}

vector<ll> sociables(ll lb, ll ub, ll ord) {
  vector<ll> res;
  for (ll i = lb; i <= ub; ++i) {
    res = vector<ll>();
    ll t = i;
    ll o = ord;
    while (o--) {
      res.push_back(t);
      t = s(t);
    }
    set<ll> st = set(res.begin(), res.end());
    if (t == i && st.size() == ord) return res;
  }
  return res;
}

void show(ll lb, ll ub, ll ord) {
  vector<ll> res = sociables(lb, ub, ord);
  for (ll i = 0; i < ord; ++i)
    printf("%lld%c", res[i], i == ord - 1 ? '\n' : ' ');
}

int main() {
  show(2, 1'000'000, 5); // 12496 14288 15472 14536 14264
  show(2, 1'000'000, 28);
  // 14316 19116 31704 47616 83328 177792 295488 629072 589786 294896 358336
  // 418904 366556 274924 275444 243760 376736 381028 285778 152990 122410 97946
  // 48976 45946 22976 22744 19916 17716
}