#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll T[MAX_N];

int main() {
  cin >> N;
  map<ll, ll> C;
  for (ll i = 0; i < N; ++i) {
    cin >> T[i];
    ++C[T[i]];
  }
  ll t = 0;
  ll pen = 0;
  ll sol = 1;
  for (auto p : C) {
    ll v = p.first;
    ll n = p.second;
    ll s = 1;
    for (ll i = 1; i <= n; ++i) {
      pen += t + v;
      t += v;
      s = s * i % MOD;
    }
    sol = sol * s % MOD;
  }
  printf("%lld\n", pen);
  printf("%lld\n", sol);
}