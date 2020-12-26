#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

vector<ll> prime_factorize(ll n) {
  vector<ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) {
    res.push_back(n);
  }
  return res;
}

void solve() {
  vector<ll> D_A = prime_factorize(A);
  vector<ll> D_B = prime_factorize(B);
  set<ll> T;
  for (auto d : D_A) {
    if (B % d == 0) {
      T.insert(d);
    }
  }
  for (auto d : D_B) {
    if (A % d == 0) {
      T.insert(d);
    }
  }
  printf("%ld\n", T.size() + 1);
}

int main() {
  cin >> A >> B;
  solve();
}