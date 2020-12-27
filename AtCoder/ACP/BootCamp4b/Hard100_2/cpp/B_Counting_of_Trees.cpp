#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

ll N;
vector<ll> D;

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

void solve() {
  if (D[0] != 0) {
    puts("0");
    return;
  }
  map<ll, ll> C;
  for (int i = 0; i < N; ++i) {
    ++C[D[i]];
  }
  if (C[0] != 1) {
    puts("0");
    return;
  }
  ll res = 1;
  ll prv = 0;
  ll prv_cnt = 1;
  for (auto p : C) {
    if (p.first == 0) continue;
    if (p.first - prv != 1) {
      res = 0;
      break;
    }
    res = res * mod_pow(prv_cnt, p.second) % MOD;
    prv = p.first;
    prv_cnt = p.second;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  D = vector<ll>(N);
  for (int i = 0; i < N; ++i) {
    cin >> D[i];
  }
  solve();
}