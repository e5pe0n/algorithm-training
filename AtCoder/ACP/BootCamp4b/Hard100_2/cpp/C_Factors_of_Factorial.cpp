#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N;

void factorize(ll n, map<ll, ll> &C) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    while (n % i == 0) {
      n /= i;
      ++C[i];
    }
  }
  if (n > 1) {
    ++C[n];
  }
}

void solve() {
  map<ll, ll> C;
  for (int i = 1; i <= N; ++i) {
    factorize(i, C);
  }
  ll res = 1;
  for (auto p : C) {
    res = res * (p.second + 1) % MOD;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  solve();
}