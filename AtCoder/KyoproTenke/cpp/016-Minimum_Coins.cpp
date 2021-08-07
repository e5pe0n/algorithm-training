#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_M = 9999;
ll N;
ll ABC[3];
ll A, B, C;

int main() {
  cin >> N;
  for (ll i = 0; i < 3; ++i) {
    cin >> ABC[i];
  }
  sort(ABC, ABC + 3);
  A = ABC[0];
  B = ABC[1];
  C = ABC[2];
  ll res = MAX_M;
  for (ll i = 0; i <= min(MAX_M, N / C); ++i) {
    ll m1 = N - C * i;
    for (ll j = 0; j <= min(MAX_M, m1 / B); ++j) {
      ll m2 = m1 - B * j;
      if (m2 % A == 0) res = min(res, i + j + m2 / A);
    }
  }
  printf("%lld\n", res);
}