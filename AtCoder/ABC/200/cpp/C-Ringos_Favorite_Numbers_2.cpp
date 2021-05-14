#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 200;

ll N;
map<ll, ll> C;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    ++C[A % 200];
  }
  ll res = 0;
  for (auto p : C) {
    res += p.second * (p.second - 1) / 2;
  }
  printf("%lld\n", res);
}