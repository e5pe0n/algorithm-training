#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> prime_factorize(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) {
        res.push_back(n / i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  string s;
  for (int i = 0; i < 10; ++i) {
    s += "7";
    ll n = stoll(s);
    vector<ll> v = prime_factorize(n);
    printf("%lld: ", n);
    for (int j = 0; j < v.size(); ++j) {
      printf("%lld%c", v[j], j == v.size() - 1 ? '\n' : ' ');
    }
  }
}