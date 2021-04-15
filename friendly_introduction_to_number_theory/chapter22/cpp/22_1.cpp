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

vector<ll> m_keys(const map<ll, ll> &m) {
  vector<ll> res;
  for (auto p : m) {
    res.push_back(p.first);
  }
  return res;
}

string v_str(const vector<ll> &v) {
  string res;
  for (auto _v : v) {
    res += to_string(_v);
    res += " ";
  }
  res.pop_back();
  return res;
}

bool is_qr(const ll &q, const ll &p) {
  for (ll i = 0; i < p; ++i) {
    ll t = i * i % p;
    if (t == q) return true;
  }
  return false;
}

int main() {
  map<ll, ll> ps85 = prime_factorize(85);
  printf("%s\n", v_str(m_keys(ps85)).c_str());

  printf("%d\n", is_qr(5, 19));

  map<ll, ll> ps68 = prime_factorize(68);
  printf("%s\n", v_str(m_keys(ps68)).c_str());

  map<ll, ll> ps31706 = prime_factorize(31706);
  printf("%s\n", v_str(m_keys(ps31706)).c_str());
}