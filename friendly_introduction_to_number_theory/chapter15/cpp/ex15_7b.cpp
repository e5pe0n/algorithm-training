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

ll sigma_p(ll p, ll k) {
  return ((ll)pow(p, k + 1) - 1) / (p - 1);
}

ll sigma(ll n) {
  map<ll, ll> ps = prime_factorize(n);
  ll res = 1;
  for (auto p : ps) {
    res *= sigma_p(p.first, p.second);
  }
  return res;
}

string disc(ll n) {
  ll s = sigma(n);
  if (s > 2 * n)
    return "abundant"; // abundant
  else if (s == 2 * n)
    return "perfect"; // perfect
  else
    return "deficient"; // deficient
}

map<string, ll> cnt(ll start, ll end) {
  map<string, ll> res;
  for (ll i = start; i <= end; ++i) {
    ++res[disc(i)];
  }
  return res;
}

void show(ll start, ll end) {
  map<string, ll> res = cnt(start, end);
  printf("[%lld, %lld]\n", start, end);
  for (auto p : res)
    printf("%s=%lld\n", p.first.c_str(), p.second);
  puts("");
}

int main() {
  show(2, 100);
  show(100, 200);
  show(100, 1000);
}